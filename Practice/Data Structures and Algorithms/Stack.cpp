#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* link;
};

template <typename T>
class Stack {

    public:
        Stack();
        Stack(const Stack<T>&);
        Stack<T>& operator = (const Stack<T>&);
        ~Stack();

        bool is_empty() const { return start == nullptr };
        int length();
        void push(const T&);
        void pop(T&);
        void top(T&) const;
        void print();

    private:
        Node<T> *start;
        void copy(const Stack<T>&);
        void delete_();
};

template <typename T>
Stack<T>::Stack() {
    start = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) {
    copy(s);
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& s) {
    if (this != &s) {
        delete_();
        copy(s);
    }

    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    delete_();
}

template <typename T>
int Stack<T>::length() {
    T x;
    int n = 0;

    while(!is_empty()) {
        pop(x);
        n++;
    }

    return n;
}

template <typename T>
void Stack<T>::push(const T& s) {
    Node<T>* p = start;
    start = new Node<T>;
    start->data = s;
    start->link = p;
}

template <typename T>
void Stack<T>::pop(T& s) {
    if (start) {
        s = start->data;
        Node<T> *p = start;
        start = start->link;
        delete p;
    }
    else {
        cout << "Stack is empty!";
    }
}

template <typename T>
void Stack<T>::top(T& s) const {
    start ? s = start->data : cout << "Stack is empty!";
}

template <typename T>
void Stack<T>::print() {
    T x;

    while(!is_empty()) {
        pop(x);
        cout << x << " ";
    }

    cout << endl;
}

template <typename T>
void Stack<T>::copy(const Stack<T>& s) {
    if(s.start) {
        Node<T> *p = s.start, *q = nullptr, *s = nullptr;
        start = new Node<T>;
        start->data = p->data;
        start->link = q;
        q = start;
        p = p->link;

        while(p) {
            s = new Node<T>;
            s->data = p->data;
            q->link = s;
            q = s;
            p = p->link;
        }

        q->link = nullptr;
    }
    else {
        start = nullptr;
    }
}

template <typename T>
void Stack<T>::delete_() {
    Node<T> *p;

    while (start) {
        p = start;
        start = start->link;
        delete p;
    }   
}

int main() {
    Stack<int> s;

    s.push(2);
    s.push(3);

    Stack<int> s1 = s, s2;
    s2 = s1;
    s2.print();

    return 0;
}