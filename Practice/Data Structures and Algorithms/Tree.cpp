#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *left, *right;
};

template <typename T>
class Tree {

    public:
        Tree();
        Tree(const Tree<T>&);
        Tree& operator = (const Tree<T>&);
        ~Tree();

        bool is_empty() const { return root == nullptr; }
        Node<T>* getRoot() const { return root; }
        T rootTree() const { return root->data; }
        Tree leftTree() const;
        Tree rightTree() const;
        void create3(const T&, const Tree<T>&, const Tree<T>&);
        void print() const { pr(root); }
        void create() { createTree(root); }

    private:
        Node<T>* root;
        void copyTree(const Tree<T>&);
        void copy(Node<T>*&, Node<T>* const&) const;
        void createTree(Node<T>*&) const;
        void pr(const Node<T>*) const;
        void delete_(const Node<T>*&) const;
};

template <typename T>
Tree<T>::Tree() {
    root = nullptr;
}

template <typename T>
Tree<T>::Tree(const Tree<T>& t) {
    copy(t);
}

template <typename T>
Tree<T>& Tree<T>::operator = (const Tree<T>& t) {
    if (this != &other) {
        delete_(root);
        copy(t);
    }

    return *this;
}

template <typename T>
Tree<T>::~Tree() {
    delete_(root);
}

template <typename T>
Tree<T> Tree<T>::leftTree() const {
    Tree<T> t;
    copy(t.root, root->left);
    return t;
}

template <typename T>
Tree<T> Tree<T>::rightTree() const {
    Tree<T> t;
    copy(t.root, root->right);
    return t;
}

template <typename T>
void Tree<T>::create3(const T& t, const Tree<T>& l, const Tree<T>& r) {
    if (root) {
        delete_(root);
    }

    root = new Node<T>;
    root->data = t;

    copy(root->left, l.root);
    copy(root->right, r.root);
}

template <typename T>
void Tree<T>::copyTree(const Tree<T>& r) {
    copy(root, r.root);
}

template <typename T>
void Tree<T>::copy(Node<T>*& p, Node<T>* const& r) const {
    p = nullptr;

    if (r) {
        p = new Node<T>;
        p->data = r->data;
        copy(root->left, r->left);
        copy(root->right, r->right);
    }
}

template <typename T>
void Tree<T>::createTree(Node<T>*& p) const {
    T x;
    char c;

    cout << "root: "; cin >> x;

    p = new Node<T>;
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;

    cin >> c;
    if (c == 'y') createTree(p->left);
    cin >> c;
    if (c == 'y') createTree(p->right);
}

template <typename T>
void Tree<T>::pr(const Node<T>* p) const {
    if (p) {
        pr(p->left);
        cout << p->data << " ";
        pr(p->right);
    }
}

template <typename T>
void Tree<T>::delete_(const Node<T>*& p) const {
    if (p) {
        delete_(p->left);
        delete_(p->right);
        delete p;
        p = nullptr;
    }
}

int main() {

    Tree<int> t;

    

    return 0;
}