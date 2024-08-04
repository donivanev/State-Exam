#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* link;
};

template <typename T>
class LList {

    public:
        LList();
        LList(const LList<T>&);
        LList<T>& operator = (const LList<T>&);
        ~LList();
        
        bool is_empty() const { return start == nullptr };
        int length() const;
        void iterStart(Node<T>* = nullptr);
        Node<T>* iter();
        void toEnd(const T&);
        void insertAfter(Node<T>*, const T&);
        void insertBefore(Node<T>*, const T&);
        void deleteAfter(Node<T>*, T&);
        void deleteBefore(Node<T>*, T&);
        void deleteElem(Node<T>*, T&);
        void concat(const LList&);
        void reverse();
        void print() const;

    private:
        Node<T> *start, *end, *current;
        void copy(const LList<T>&);
        void delete_();
};

template <typename T>
LList<T>::LList() {
    start = end = nullptr;
}

template <typename T>
LList<T>::LList(const LList<T>& l) {
    copy(l);
}

template <typename T>
LList<T>& LList<T>::operator = (const LList<T>& l) {
    if (this != &l) {
        delete_();
        copy(l);
    }

    return *this;
}

template <typename T>
LList<T>::~LList() {
    delete_();
}

template <typename T>
int LList<T>::length() const {
    int n = 0;
    Node<T> *p = start;

    while (p) {
        n++;
        p = p->link;
    }
    
    return n;
}

template <typename T>
void LList<T>::iterStart(Node<T> *l) {
    l ? current = p : current = start;
}

template <typename T>
Node<T>* LList<T>::iter() {
    Node<T> *l = current;

    if (current) {
        current = current->link;
    }

    return l;
}

template <typename T>
void LList<T>::toEnd(const T& l) {
    Node<T> *p = end;
    end = new Node<T>;
    end->data = l;
    end->link = nullptr;
    p ? p->link = end : start = end;
}

template <typename T>
void LList<T>::insertAfter(Node<T>* p, const T& l) {
    Node<T> *q = new Node<T>;
    q->data = l;
    q->link = p->link;

    if (p == end) {
        end = q;
    }

    p->link = q;
}

template <typename T>
void LList<T>::insertBefore(Node<T>* p, const T& l) {
    Node<T> *q = new Node<T>;
    *q = *p;

    if (p == end) {
        end = q;
    }

    p->data = l;
    p->link = q;
}

template <typename T>
void LList<T>::deleteAfter(Node<T>* p, T& l) {
    if (p->link) {
        Node<T> *q = p->link;
        l = q->data;
        p->link = q->link;

        if (q == end) {
            end = p;
        }

        delete q;
    }
    else {
        cout << "No elements after p";
    }
}

template <typename T>
void LList<T>::deleteBefore(Node<T>* p, T& l) {
    if (p != start) {
        Node<T> *q = start;
        
        while (q->link != p) {
            q = q->link;
        }
        
        deleteElem(q, l);
    }
    else {
        cout << "No elements after p";
    }
}

template <typename T>
void LList<T>::deleteElem(Node<T>* p, T& l) {
    if (p == start) {
        l = p->data;
        
        start == end ? start = end = nullptr : start = start->link;
        
        delete p;
    }
    else {
        Node<T> *q = start;
        
        while (q->link != p) {
            q = q->link;
        }
        
        deleteAfter(q, l);
    }
}

template <typename T>
void LList<T>::concat(const LList& l) {
    Node<T> *p = l.start;

    while (p) {
        toEnd(p->data);
        p = p->link;
    }
    
    cout << endl;
}

template <typename T>
void LList<T>::reverse() {
    Node<T> *p, *q, *temp;
    p = start;

    if (p) {
        q = nullptr;
        temp = start;
        start = end;
        end = temp;

        while (p != start) {
            temp = p->link;
            p->link = q;
            q = p;
            p = temp;
        }
        
        p->link = q;
    }
}

template <typename T>
void LList<T>::print() const {
    Node<T> *p = start;

    while (p) {
        cout << p->data << " ";
        p = p->link;
    }
    
    cout << endl;
}

template <typename T>
void LList<T>::copy(const LList<T>& l) {
    Node<T> *p = l.start, *q;
    
    if (l.start) {
        start = new Node<T>;
        end = start;

        while(p) {
            end->data = p->data;
            end->link = nullptr;
            p = p->link;

            if(p) {
                q = end;
                end = new Node<T>;
                q->link = end;
            }
        }
    }
    else {
        start = end = nullptr;
    }
}

template <typename T>
void LList<T>::delete_() {
    Node<T> *p;

    while (start) {
        p = start;
        start = start->link;
        delete p;
    }
    
    end = nullptr;
}

int main() {
    LList<int> l;

    l.print();

    return 0;
}
