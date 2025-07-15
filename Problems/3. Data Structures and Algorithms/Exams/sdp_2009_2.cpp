#include <iostream>
using namespace std;

/*
Да се дефинира тип данни, описващ възел на двоично дърво от цели числа.
Да се напише булева функция, която проверява дали дадено двоично дърво е балансирано.
Едно двоично дърво е балансирано, ако за всеки негов връх v, височините на лявото и дясното поддървета на v се различават най-много с 1.
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int checkHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    // Recursively get the height of the left and right subtrees
    int leftHeight = checkHeight(node->left);

    if (leftHeight == -1)
        return -1; // Not balanced

    int rightHeight = checkHeight(node->right);
    
    if (rightHeight == -1)
        return -1; // Not balanced

    // Check if the current node is balanced
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Not balanced
    }
    else {
        return max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}

int main() {

    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Check if the tree is balanced
    isBalanced(root) ? cout << "The tree is balanced." << endl : cout << "The tree is not balanced." << endl;

    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}