#include <iostream>
using std::cout; using std::endl;

template <typename T>
struct Node {
    T data;
    Node<T> *left, *right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
    public:
        Tree();
        Tree(const Tree<T>& t);
        Tree<T>& operator = (const Tree<T>& t);
        ~Tree();

        bool empty() const { return root == nullptr; }
        void insert(const T& value) { insert(root, value); }
        void remove(const T& value) { root = remove(root, value); }
        bool search(const T& value) const { return search(root, value); }
        int height() const { return height(root); }
        int count_nodes() const { return count_nodes(root); }
        bool is_balanced() const { return is_balanced(root); }
        void inorder() const { inorder(root); }
        void clear() { clear(root); root = nullptr; }

    private:
        Node<T>* root;

        int height(Node<T>* node) const;
        void insert(Node<T>*& node, const T& value);
        Node<T>* find_min(Node<T>* node) const;
        Node<T>* remove(Node<T>* node, const T& value);
        bool search(Node<T>* node, const T& value) const;
        int count_nodes(Node<T>* node) const;
        bool is_balanced(Node<T>* node) const;
        void inorder(Node<T>* node) const;

        Node<T>* copy(Node<T>* t) const;
        void clear(Node<T>*& node);
};

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::Tree(const Tree<T>& t) {
    root = copy(t.root);
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree<T>& t) {
    if (this != &t) {
        clear(root);
        root = copy(t.root);
    }

    return *this;
}

template <typename T>
Tree<T>::~Tree() {
    clear(root);
}

template <typename T>
void Tree<T>::insert(Node<T>*& node, const T& value) {
    if (node == nullptr) {
        node = new Node<T>(value);
    }
    else if (value < node->data) {
        insert(node->left, value);
    } 
    else {
        insert(node->right, value);
    }
}

template <typename T>
Node<T>* Tree<T>::find_min(Node<T>* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

template <typename T>
Node<T>* Tree<T>::remove(Node<T>* node, const T& value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = remove(node->left, value);
    } 
    else if (value > node->data) {
        node->right = remove(node->right, value);
    } 
    else {
        if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } 
        else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T>* temp = find_min(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

template <typename T>
bool Tree<T>::search(Node<T>* node, const T& value) const {
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    }
    else if (value < node->data) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

template <typename T>
int Tree<T>::height(Node<T>* node) const {
    if (node == nullptr) {
        return 0;
    }

    // int left_height = height(node->left);
    // int right_height = height(node->right);
    
    return 1 + max(height(node->left), height(node->right));
}

template <typename T>
int Tree<T>::count_nodes(Node<T>* node) const {
    if (node == nullptr) {
        return 0;
    }

    return 1 + count_nodes(node->left) + count_nodes(node->right);
}

template <typename T>
bool Tree<T>::is_balanced(Node<T>* node) const {
    if (node == nullptr) {
        return true;
    }

    int lh = height(node->left);
    int rh = height(node->right);

    if (abs(lh - rh) > 1) {
        return false;
    }

    return is_balanced(node->left) && is_balanced(node->right);
}

template <typename T>
void Tree<T>::inorder(Node<T>* node) const {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Pre-order traversal (Root-Left-Right)
    // cout << node->data << " ";
    // preorder(node->left);
    // preorder(node->right);

    // Post-order traversal (Left-Right-Root)
    // postorder(node->left);
    // postorder(node->right);
    // cout << node->data << " ";
}

template <typename T>
Node<T>* Tree<T>::copy(Node<T>* t) const {
    if (t == nullptr) {
        return nullptr;
    }

    Node<T>* newNode = new Node<T>(t->data);
    newNode->left = copy(t->left);
    newNode->right = copy(t->right);

    return newNode;
}

template <typename T>
void Tree<T>::clear(Node<T>*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

int main() {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);

    cout << "Inorder traversal: ";
    tree.inorder();

    Tree<int> tree2 = tree;  // Using copy constructor
    cout << "Copy of tree (inorder): ";
    tree2.inorder();

    tree2.remove(10);
    cout << "After deleting 10 from copied tree: ";
    tree2.inorder();

    tree2 = tree;  // Using assignment operator
    cout << "After assignment, inorder: ";
    tree2.inorder();

    return 0;
}