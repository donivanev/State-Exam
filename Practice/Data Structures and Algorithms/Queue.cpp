#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* link;
};

template <typename T>
class Queue {

    public:
        Queue();
        Queue(const Queue<T>&);
        Queue<T>& operator = (const Queue<T>&);
        ~Queue();

        bool is_empty() const { return end == nullptr };
        int length();
        void push(const T&);
        void pop(T&);
        void head(T&) const;
        void print();

    private:
        Node<T> *start, *end;
        void copy(const Queue&);
        void delete_();
};

template <typename T>
Queue<T>::Queue() {
    start = end = nullptr;
}


template <typename T>
Queue<T>::Queue(const Queue<T>& q) {
    copy(q);
}

template <typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& q) {
    if(this != &q) {
        delete_();
        copy(q);
    }

    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    delete_();
}

template <typename T>
int Queue<T>::length() {
    T x;
    int n = 0;

    while(!is_empty()) {
        pop(x);
        n++;
    }

    return n;
}

template <typename T>
void Queue<T>::push(const T& q) {
    Node<T>* p = start;
    start = new Node<T>;
    p->data = q;
    p->link = nullptr;

    if (end) {
        end->link = p;
    }
    else {
        start = p;
    }
    
    end = p;
}

template <typename T>
void Queue<T>::pop(T& q) {
    if (!is_empty()) {
        Node<T> *p = start;
        q = p->link;
        
        if (p == end) {
            end = nullptr;
            start = nullptr;
        }
        else {
            start = p->link;
        }
        
        delete p;
    }
    else {
        cout << "Queue is empty!";
    }
}

template <typename T>
void Queue<T>::head(T& q) const {
    !is_empty() ? q = start->data : cout << "Queue is empty!";
}

template <typename T>
void Queue<T>::copy(const Queue<T>& q) {
    start = end = nullptr;
    Node<T> *p = q.front;

    while (p) {
        push(p->data);
        p = p->link;
    }
}

template <typename T>
void Queue<T>::delete_() {
    T x;

    while (!is_empty()) {
        pop(x);
    }
}

template <typename T>
void Queue<T>::print() {
    T x;

    while(!is_empty()) {
        pop(x);
        cout << x << " ";
    }

    cout << endl;
}

int main() {
    Queue<int> q;

    q.push(2);
    q.push(3);

    return 0;
}