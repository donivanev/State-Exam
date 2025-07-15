#include <iostream>
#include <stdexcept>
using std::cout; using std::endl; using std::runtime_error;

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
    public:
        Queue();
        Queue(const Queue<T>&);
        Queue<T>& operator = (const Queue<T>&);
        ~Queue();

        bool empty() const { return front == nullptr; }
        unsigned length() const { return size; }
        void push(const T&);
        void pop();
        T& head() const;
        // back ??

    private:
        Node<T> *front, *back;
        unsigned size;
        void copy(const Queue<T>&);
        void clear();
};

template <typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr), size(0) {}

template <typename T>
Queue<T>::Queue(const Queue<T>& q) {
    copy(q);
}

template <typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& q) {
    if(this != &q) {
        clear();
        copy(q);
    }

    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

template <typename T>
void Queue<T>::push(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (empty()) {
        front = newNode;
    }
    else {
        back->next = newNode;
    }

    back = newNode;
    size++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node<T>* curr = front;
    front = front->next;

    if (front == nullptr) {
        back = nullptr;
    }

    delete curr;
    size--;
}

template <typename T>
T& Queue<T>::head() const {
    if (empty()) throw runtime_error("Queue is empty!");
    return front->data;
}

template <typename T>
void Queue<T>::copy(const Queue<T>& q) {
    front = back = nullptr;
    Node<T> *curr = q.front;

    while (curr != nullptr) {
        push(curr->data);
        curr = curr->next;
    }
}

template <typename T>
void Queue<T>::clear() {
    while (!empty()) {
        pop();
    }
}

int main() {
    Queue<int> q;

    q.push(2);
    q.push(3);

    cout << q.head(); // Output: 2
    q.pop();

    return 0;
}