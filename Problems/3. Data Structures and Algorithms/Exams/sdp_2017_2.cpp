#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Напишете функция, която получава като аргумент свързан списък с елементи свързани списъци от цели числа.
Някои от тези списъци ще са сортирани, други не. Вашата задача е да върнете като резултат нов сортиран списък от цели числа,
получен чрез сливането на всички сортирани списъци. Напишете кратка програма, която демонстрира използването на горната функция.
*/

struct IntNode {
    int data;
    IntNode* next;
    IntNode(int d) : data(d), next(nullptr) {}
};

struct ListNode {
    IntNode* list;     // вътрешен списък
    ListNode* next;    // сочи към следващия външен списък
    ListNode(IntNode* l) : list(l), next(nullptr) {}
};

bool isSorted(IntNode* head) {
    while (head && head->next) {
        if (head->data > head->next->data)
            return false;
        head = head->next;
    }

    return true;
}

IntNode* mergeSortedLists(ListNode* lists) {
    vector<int> values;

    while (lists) {
        if (isSorted(lists->list)) {
            IntNode* curr = lists->list;

            while (curr) {
                values.push_back(curr->data);
                curr = curr->next;
            }
        }

        lists = lists->next;
    }

    sort(values.begin(), values.end());

    // Създаваме нов списък от сортираните стойности
    IntNode *result = nullptr, *tail = nullptr;

    for (int val : values) {
        IntNode* node = new IntNode(val);

        if (!result) {
            result = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    return result;
}

IntNode* createList(const initializer_list<int>& vals) {
    IntNode *head = nullptr, *tail = nullptr;

    for (int val : vals) {
        IntNode* node = new IntNode(val);

        if (!head) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

void printList(IntNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Създаваме няколко вътрешни списъка
    IntNode* l1 = createList({1, 3, 5});      // сортиран
    IntNode* l2 = createList({4, 2, 7});      // НЕсортиран
    IntNode* l3 = createList({6, 8, 9});      // сортиран

    // Създаваме външния списък от списъци
    ListNode* outer = new ListNode(l1);
    outer->next = new ListNode(l2);
    outer->next->next = new ListNode(l3);

    // Извикваме функцията
    IntNode* result = mergeSortedLists(outer);

    // Извеждаме резултата
    cout << "Обединен сортиран списък: ";
    printList(result);

    return 0;
}