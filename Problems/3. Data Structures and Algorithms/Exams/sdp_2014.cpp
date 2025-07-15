#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*
Едносвързан цикличен списък от цели числа се описва с референция (указател) към циклична верига от двойни клетки, представени по следния начин:
    struct Node {
        Node *next;
        int  data;
    };
А) За даден цикличен списък L казваме, че числото M предхожда числото N, ако в списъка L има кутия A, която съдържа M, а A.next сочи към кутия,
която съдържа N. Да се реализира (статична) функция precedes, която по даден списък L и две числа M и N проверява дали M предхожда N в L и ако е така,
връща референция (указател) към кутията A, която съдържа M.
Б) Ако са дадени два списъка L1 и L2, така че M предхожда N в L1 и N предхожда M в L2, тогава двата списъка могат да се слеят в един списък L, 
както е показано на диаграмата долу, така че в L остава само по един екземпляр на числата M и N. Да се реализира (статична) функция merge, която
слива два списъка L1 и L2, ако това е възможно. В случай, че сливането може да стане по няколко различни начина, да се избере такъв, за който
сумата на числата M и N е максимална.
В) Да се реализира (статична) функция split, която по даден списък L и числа M и N, ако е възможно, разделя списъка L на два списъка L1 и L2,
така че M предхожда N в L1 и N предхожда M в L2, както е показано на диаграмата горе. Ако разделянето може да стане по повече от един начин,
да се избере такъв, при който разликата между дължините на получените списъци L1 и L2 е минимална.
*/

struct Node {
    int data;
    Node *next;
};

static Node* precedes(Node* l, int m, int n) {
    if (!l) return nullptr;

    Node *start = l, *current = l;

    do {
        if (current->data == m && current->next->data == n)
            return current;
        current = current->next;
    } while (current != start);

    return nullptr;
}

static Node* merge(Node* l1, Node* l2) {
    if (!l1 || !l2) return nullptr;

    Node *bestM = nullptr, *bestN = nullptr;
    int maxSum = INT_MIN;

    Node* p1 = l1;
    do {
        int m = p1->data;
        int n = p1->next->data;
        Node* match = precedes(l2, n, m);
        
        if (match && (m + n > maxSum)) {
            bestM = p1;
            bestN = match;
            maxSum = m + n;
        }
        
        p1 = p1->next;
    } while (p1 != l1);

    if (!bestM || !bestN) return nullptr;

    // пренасочване на връзките: M->N (от l1), N->M (от l2)
    Node* temp = bestN->next;         // N -> ...
    bestN->next = bestM->next;        // N -> node след M
    bestM->next = temp;               // M -> node след N

    return bestM; // новата референция към слетия списък
}
// Помощна функция: връща дължина на цикличен списък
int length(Node* start) {
    if (!start) return 0;
    int count = 1;
    Node* curr = start->next;
    while (curr != start) {
        count++;
        curr = curr->next;
    }
    return count;
}

static bool split(Node* l, int m, int n, Node*& outL1, Node*& outL2) {
    if (!l) return false;

    Node *bestM = nullptr, *bestN = nullptr;
    int bestDiff = INT_MAX;

    Node* curr = l;

    do {
        if (curr->data == m && curr->next->data == n) {
            Node* candidateM = curr;

            // Потърси n->m
            Node* search = l;
            do {
                if (search->data == n && search->next->data == m && search != candidateM->next) {
                    Node* candidateN = search;

                    // Раздели временно
                    candidateM->next = candidateM->next->next;
                    candidateN->next = candidateN->next->next;

                    int len1 = length(candidateM->next);
                    int len2 = length(candidateN->next);
                    int diff = abs(len1 - len2);

                    // Върни връзките обратно
                    candidateM->next = candidateM->next->next->next;
                    candidateN->next = candidateN->next->next->next;

                    if (diff < bestDiff) {
                        bestM = candidateM;
                        bestN = candidateN;
                        bestDiff = diff;
                    }
                }

                search = search->next;
            } while (search != l);
        }
        curr = curr->next;
    } while (curr != l);

    if (!bestM || !bestN) return false;

    // Реално разделяне
    outL1 = bestM->next;
    outL2 = bestN->next;
    bestM->next = outL1;
    bestN->next = outL2;

    return true;
}

Node* createCycle(const vector<int>& vals) {
    Node* head = nullptr;
    Node* prev = nullptr;
    for (int val : vals) {
        Node* node = new Node{val, nullptr};
        if (!head) head = node;
        if (prev) prev->next = node;
        prev = node;
    }
    
    if (prev)
        prev->next = head; // затваряне в цикъл
    
    return head;
}

void printCycle(Node* start, int maxNodes = 20) {
    Node* curr = start;
    int count = 0;

    do {
        cout << curr->data << " ";
        curr = curr->next;
        count++;
    } while (curr != start && count < maxNodes);

    cout << "...\n";
}

int main() {
    Node* l1 = createCycle({1, 2, 3, 4});
    Node* l2 = createCycle({3, 1, 5, 6});

    Node* found = precedes(l1, 2, 3);
    if (found)
        cout << "Precedes: " << found->data << "\n";

    Node* merged = merge(l1, l2);
    if (merged) {
        cout << "Merged: ";
        printCycle(merged);
    }

    Node* splitL1 = nullptr;
    Node* splitL2 = nullptr;
    if (split(merged, 2, 3, splitL1, splitL2)) {
        cout << "Split L1: "; printCycle(splitL1);
        cout << "Split L2: "; printCycle(splitL2);
    }

    return 0;
}