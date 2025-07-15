#include <iostream>
#include <cstring>
using namespace std;

/*
Да се дефинира клас BinTree, който представя двоично дърво с наредба на синовете и ориентация на ребрата от родител към дете, надписано
със символи по върховете. Ориентираният път между два върха на дървото се представя с низа от надписите на последователните върхове на пътя.
    • Да се дефинират член-данни и помощни структури за класа BinTree, които са необходими за избраното представяне.
    • Да се реализира член-функция isSymmetric(), която проверява дали двоичното дърво е симетрично относно наредбата на синовете (ляво-дясно),
    т.е. дали съвпада с огледалния си образ.
    • Да се реализира член-функция appendTree(t) която вмъква дадено двоично дърво t на мястото на всички листа на дървото, чиито надписи
    съвпадат с надписа в корена на t.
    • Да се реализира член-функция contains(s), която проверява дали даден низ s представя път в дървото. 
*/

struct Node {
    char label;
    Node *left, *right;

    Node(char c) : label(c), left(nullptr), right(nullptr) {}
};

class BinTree {
    public:
        BinTree() { root = nullptr; }
        ~BinTree() { destroy(root); }

        Node* getRoot() { return root; }
        void insertRoot(char label) {
            if (!root) {
                root = new Node(label);
            }
        }
        bool isSymmetric(Node* root);
        void appendTree(BinTree& t);
        bool contains(char* str);

    private:
        char data;
        Node* root;
        Node* cloneTree(Node* node);
        bool isSymmetricHelper(Node* left, Node* right);
        void appendTreeHelper(Node* node, Node* tRoot);
        bool containsHelper(Node* node, char* str, int index);
        void destroy(Node* root);
};

bool BinTree::isSymmetricHelper(Node* left, Node* right) {
    if (!left && !right) {
        return true;
    }

    if (!left || !right) {
        return false;
    }
    
    return (left->label == right->label) &&
        isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool BinTree::isSymmetric(Node* root) {
    if (!root) {
        return true;
    }

    return isSymmetricHelper(root->left, root->right);
}

Node* BinTree::cloneTree(Node* node) {
    if (!node) return nullptr;
    Node* newNode = new Node(node->label);
    newNode->left = cloneTree(node->left);
    newNode->right = cloneTree(node->right);
    return newNode;
}

void BinTree::appendTreeHelper(Node* node, Node* tRoot) {
    if (!node) {
        return;
    }

    if (!node->left && !node->right && node->label == tRoot->label) {
        Node* copy = cloneTree(tRoot);
        node->left = copy->left;
        node->right = copy->right;
        delete copy; // освобождаваме временния корен, пазим само поддърветата
        return;
    }

    appendTreeHelper(node->left, tRoot);
    appendTreeHelper(node->right, tRoot);
}

void BinTree::appendTree(BinTree& t) {
    if (!root || !t.root) {
        return;
    }
    
    appendTreeHelper(root, t.root);
}

bool BinTree::containsHelper(Node* node, char* str, int index) {
    if (!node) {
        return false;
    }

    if (index == strlen(str) - 1) {
        return node->label == str[index];
    }
    
    if (node->label != str[index]) {
        return false;
    }

    return containsHelper(node->left, str, index + 1) || containsHelper(node->right, str, index + 1);   
}

bool BinTree::contains(char* str) {
    if (!root) {
        return false;
    }
    
    return containsHelper(root, str, 0);
}

void BinTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int main() {
    
    BinTree* bt = new BinTree;
    bt->insertRoot('a');


    return 0;
}