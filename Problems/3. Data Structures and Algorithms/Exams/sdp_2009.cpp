#include <iostream>
using namespace std;

/*
Да се дефинира тип данни, описващ възел в линеен едносвързан списък от цели числа.
Да се напише булева функция, която проверява дали в даден едносвързан списък съществува цикъл.
Цикъл наричаме такава редица от указатели към съседни възли, в която поне един указател се среща повече от веднъж.
*/

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Floyd's Cycle Detection algorithm
bool hasCycle(Node* head) {
    if (head == nullptr) {
        return false; // An empty list has no cycle
    }
    
    Node* slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        if (slow == fast) {
            return true; // If the two pointers meet, there's a cycle
        }
    }

    return false;
}

int main() {
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Uncomment the next line to create a loop in the list:
    // fourth->next = second;

    hasCycle(head) ? cout << "Cycle detected." << endl : cout << "No cycle detected." << endl;

    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}