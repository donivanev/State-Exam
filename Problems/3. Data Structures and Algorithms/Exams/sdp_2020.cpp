#include <iostream>
using namespace std;

/*
Цикличен едносвързан списък наричаме линеен едносвързан списък, в който указателят за следващ елемент на последния елемент
сочи към първия елемент, вместо да е нулев. Да се реализира функция void unite(Node* list), която получава като параметър
указател към елемент на цикличен едносвързан списък от символни низове, описан от следната структура:
    struct Node {
        std::string text;
        Node* next;
    };
Функцията да обединява всички двойки последователни елементи на списъка, за които последният символ на единия елемент съвпада
с първия символ на непосредствено следващия го елемент, в общ елемент, чийто низ е съставен от слепването на низовете на двата
елемента, разделени с тире. Да се демонстрира работата на функцията в кратка програма, която прочита низове от стандартния вход
(по един на ред), добавя ги в съответния цикличен списък, подава го на функцията unite и извежда последователно елементите на
променения списък на стандартния изход, започвайки от лексикографски най-малкия низ.

Пример:
Вход:
street
taxi
ink
dog
smile
eat
tall
pass
Изход:
dog
smile-eat-tall
pass-street-taxi-ink
*/

struct Node {
    string text;
    Node* next;

    Node(const string& t) : text(t), next(nullptr) {}
};

void addElement(Node*& head, const std::string& newText) {
    Node* newNode = new Node(newText);

    if (!head) {
        head = newNode;
        head->next = head;
        return;
    }

    Node* curr = head;

    while (curr->next != head) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->next = head;
}

void unite(Node*& head) {
    if (!head || head->next == head)
        return;

    Node* curr = head;

    do {
        Node* next = curr->next;

        if (curr->text.back() == next->text.front()) {
            curr->text += "-" + next->text;
            curr->next = next->next;

            if (next == head) {
                head = curr;  // ако трием главата
            }
            
            delete next;
        }
        else {
            curr = curr->next;
        }
    } while (curr->next != head);
}

void printList(Node* head) {
    if (!head)
        return;

    // намираме най-малкия
    Node* start = head, *curr = head->next;
    while (curr != head) {
        if (curr->text < start->text)
            start = curr;
        curr = curr->next;
    }

    // обхождане от start
    curr = start;

    do {
        cout << curr->text << endl;
        curr = curr->next;
    } while (curr != start);
}

void deleteList(Node*& head) {
    if (!head)
        return;

    Node* curr = head->next;

    while (curr != head) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}

int main() {
    Node* list = nullptr;
    string line;

    while (getline(cin, line) && !line.empty()) {
        addElement(list, line);
    }

    unite(list);

    printList(list);
    deleteList(list);

    return 0;
}
