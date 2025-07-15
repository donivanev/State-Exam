#include <iostream>
#include <queue>
using std::cout; using std::queue;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void bfs(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left != nullptr) { // or just current->left
            q.push(curr->left);
        }

        if (curr->right != nullptr) { // or just current->left
            q.push(curr->right);
        }
    }
}

// Depth-First Search (DFS) - Preorder Traversal (Recursive)
void dfsPreorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    dfsPreorder(root->left);
    dfsPreorder(root->right);
}

// Depth-First Search (DFS) - Inorder Traversal (Recursive)
void dfsInorder(Node* root) {
    if (root == nullptr) return;
    dfsInorder(root->left);
    cout << root->data << " ";
    dfsInorder(root->right);
}

// Depth-First Search (DFS) - Postorder Traversal (Recursive)
void dfsPostorder(Node* root) {
    if (root == nullptr) return;
    dfsPostorder(root->left);
    dfsPostorder(root->right);
    cout << root->data << " ";
}

int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    
    return countLeaves(root->left) + countLeaves(root->right);
}

bool isMirror(Node* left, Node* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }

    if (left == nullptr || right == nullptr) {
        return false;
    }

    if (left->data != right->data) {
        return false;
    }

    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(Node* root) {
    if (root == nullptr) {
        return true;
    }

    return isMirror(root->left, root->right);
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    if (isSymmetric(root))
        cout << "Symmetric.\n";
    else
        cout << "Non-symmetric.\n";

    return 0;
}