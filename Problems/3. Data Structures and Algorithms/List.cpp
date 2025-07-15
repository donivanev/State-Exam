#include <iostream>
using std::cout; using std::endl;

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class List {
    public:
        List();
        List(const List<T>&);
        List<T>& operator = (const List<T>&);
        ~List();
        
        bool empty() const { return head == nullptr; }
        unsigned length() const { return size; }
        void push_front(const T& value);
        void push_back(const T& value);
        bool remove(const T& value);
        Node<T>* search(const T& value) const;
        void reverse();
        void print() const;

    private:
        Node<T> *head, *tail;
        unsigned size;
        void copy(const List<T>&);
        void clear();
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
List<T>::List(const List<T>& l) {
    copy(l);
}

template <typename T>
List<T>& List<T>::operator = (const List<T>& l) {
    if (this != &l) {
        clear();
        copy(l);
    }

    return *this;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }

    size++;
}

template <typename T>
void List<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);

    if (empty()) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }

    tail = newNode;
    size++;
}

template <typename T>
bool List<T>::remove(const T& value) {
    Node<T>* curr = head, *prev = nullptr;

    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false; // Element not found
    }

    if (prev == nullptr) {  // Removing the first node
        head = head->next;

        if (head == nullptr) {
            tail = nullptr; // List became empty
        }
    }
    else { // Removing any other node
        prev->next = curr->next;
        
        if (curr == tail) {
            tail = prev;
        }
    }

    delete curr;
    size--;
    return true;
}

template <typename T>
Node<T>* List<T>::search(const T& value) const {
    Node<T>* curr = head;

    while (curr != nullptr) {
        if (curr->data == value) {
            return curr;
        }

        curr = curr->next;
    }

    return nullptr;
}

template <typename T>
void List<T>::reverse() {
    Node<T>* prev = nullptr, *curr = head, *next = nullptr;
    tail = head;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

template <typename T>
void List<T>::print() const {
    Node<T>* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }

    cout << endl;
}

template <typename T>
void List<T>::copy(const List<T>& l) {
    Node<T>* curr = l.head;

    while (curr != nullptr) {
        push_back(curr->data);
        curr = curr->next;
    }
}

template <typename T>
void List<T>::clear() {
    Node<T>* curr = head;

    while (curr != nullptr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = tail = nullptr;
}

int main() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.print();  // 0 -> 1 -> 2 -> nullptr

    list.reverse();
    list.print();  // 2 -> 1 -> 0 -> nullptr

    list.remove(1);
    list.print();  // 2 -> 0 -> nullptr

    return 0;
}