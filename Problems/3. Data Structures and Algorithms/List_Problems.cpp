#include <iostream>
#include <list>
using std::cout; using std::endl;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
void print(Node<T>* head) {
    Node<T>* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
}

// Floyd's Cycle Detection algorithm
template <typename T>
bool hasCycle(Node<T>* head) {
    if (head == nullptr) {
        return false; // An empty list has no cycle
    }
    
    Node<T>* slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        if (slow == fast) {
            return true; // If the two pointers meet, there's a cycle
        }
    }

    return false;
}

// Reverse a Linked List
template <typename T>
Node<T>* reverse(Node<T>* head) {
    Node<T>* prev = nullptr, *curr = head, *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move prev one step forward
        curr = next;        // Move current one step forward
    }

    return prev;
}

// Bubble sort - not recommended
template <typename T>
void sort(Node<T>* head) {
    for (Node<T>* i = head; i->next != nullptr; i = i->next) {
        for (Node<T>* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                swap(j->data, j->next->data);
            }
        }
    }
}

// Merge sort
template <typename T>
Node<T>* merge(Node<T>* a, Node<T>* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    }
    else {
        b->next = merge(a, b->next);
        return b;
    }
}

template <typename T>
Node<T>* mergeSort(Node<T>* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // Find middle
    Node<T> *slow = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node<T> *mid = slow->next;
    slow->next = nullptr;

    Node<T> *left = mergeSort(head), *right = mergeSort(mid);
    return merge(left, right);
}

int main() {
    // Create list: 3 -> 1 -> 4 -> 2
    Node<int>* head = new Node<int>{3, nullptr};
    head->next = new Node<int>{1, nullptr};
    head->next->next = new Node<int>{4, nullptr};
    head->next->next->next = new Node<int>{2, nullptr};

    print(head);

    return 0;
}