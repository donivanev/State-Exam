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
class Stack {
    public:
        Stack();
        Stack(const Stack<T>&);
        Stack<T>& operator = (const Stack<T>&);
        ~Stack();

        bool empty() const { return top == nullptr; }
        unsigned length() const { return size; }
        void push(const T&);
        void pop();
        T& peek() const;

    private:
        Node<T> *top;
        unsigned size;
        void copy(const Stack<T>&);
        void clear();
};

template <typename T>
Stack<T>::Stack() : top(nullptr), size(0) {}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
    copy(s);
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& s) {
    if (this != &s) {
        clear();
        copy(s);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    clear();
}

template <typename T>
void Stack<T>::push(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = top;
    top = newNode;
    size++;
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    
    Node<T>* curr = top;
    top = top->next;
    delete curr;
    size--;
}

template <typename T>
T& Stack<T>::peek() const {
    if (empty()) throw runtime_error("Stack is empty!");
    return top->data;
}

template <typename T>
void Stack<T>::copy(const Stack<T>& s) {
    Stack<T> temp;
    Node<T>* curr = s.top;

    // Обратен ред
    while (curr != nullptr) {
        temp.push(curr->data);
        curr = curr->next;
    }

    // Обратно в правилния ред
    curr = temp.top;
    
    while (curr != nullptr) {
        push(curr->data);
        curr = curr->next;
    }
}

template <typename T>
void Stack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

int main() {
    Stack<int> s;

    s.push(2);
    s.push(3);

    cout << s.peek() << endl;
    cout << s.length();

    Stack<int> s1 = s, s2;
    s2 = s1;

    return 0;
}