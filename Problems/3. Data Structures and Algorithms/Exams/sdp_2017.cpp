#include <iostream>
using namespace std;

/*
Напишете функция, която получава като аргумент свързан списък с елементи цели числа и го сортира.
Списъкът е представен и подаден на функцията по избран от вас начин.
Напишете кратка програма, която създава списък, добавя в него няколко елемента, използва функцията за сортиране и извежда на екрана резултата.
*/

struct Node {
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

int listLength(Node* head) {
    int count = 0;
    Node *curr = head;

    while (curr != nullptr) { // if (curr)
        count++;
        curr = curr->next;
    }

    return count;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;
}

// Bubble sort
void sortList(Node* head) {
    if (head == nullptr) {
        return;
    }

    int len = listLength(head);
    
    for (int i = 0; i < len; i++) {
        Node *curr = head, *next = head->next;
        for (int j = 0; j < len - i - 1; j++) {
            if (curr->data > next->data) {
                int temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            curr = next;
            next = next->next;
        }
    }
}

// ____________________________________________

bool isSorted(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
    while (head->next != nullptr) {
        if (head->data > head->next->data) {
            return false;
        }
        
        head = head->next;
    }
    
    return true;
}

Node* mergeListsHelper(Node* l1, Node* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }
    
    Node* result = nullptr;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeListsHelper(l1->next, l2);
    }
    else {
        result = l2;
        result->next = mergeListsHelper(l1, l2->next);
    }

    return result;
}

Node* mergeLists(Node* head) {
    Node* result = nullptr;

    while (head != nullptr) {
        if (isSorted(head->next)) {
            result = mergeListsHelper(result, head->next);
        }
        
        head = head->next;
    }
    
    return result;
}

int main() {
    
    Node* list = new Node(2);
    list->next = new Node(1);
    list->next->next = new Node(4);
    list->next->next->next = new Node(3);

    printList(list);
    sortList(list);
    printList(list);

    delete list;

    return 0;
}