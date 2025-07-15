#include <iostream>
using namespace std;

/*
Да се реализира подходящо представяне на двоично дърво за търсене. За избраното представяне да се реализират операциите добавяне
на елемент и търсене на елемент по стойност. Да се състави функция, която по дадено такова дърво извлича в нарастващ ред всички
елементи, които са на определена дълбочина.
_________________________________________________

Да се реализира подходящо представяне на граф. За така представения граф да се реализира функция, която намира всички върхове,
до които имат път от подаден връх с определена дължина в брой ребра.
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// !!! *& !!!
void insert(Node*& root, int x) {
    if (root == nullptr) {
        root = new Node(x);
    }
    else if (x < root->data) {
        insert(root->left, x);
    }
    else if (x > root->data) {
        insert(root->right, x);
    }
}

bool searchByValue(Node* root, int x) {
    if (root == nullptr) {
        return false;
    }
    else if (x == root->data) {
        return true;
    }
    else if (x < root->data) {
        return searchByValue(root->left, x);
    }
    else {
        return searchByValue(root->right, x);
    }
}

void findElementsAtDepth(Node* root, int depth, int* result, int& index, int currDepth) {
    if (root == nullptr) {
        return;
    }

    if (currDepth == depth) {
        result[index++] = root->data;
    }
    else {
        findElementsAtDepth(root->left, depth, result, index, currDepth + 1);
        findElementsAtDepth(root->right, depth, result, index, currDepth + 1);
    }
}

int* getElementsAtDepth(Node* root, int depth, int& size) {
    size = 1000;
    int* result = new int[size];
    int index = 0;

    findElementsAtDepth(root, depth, result, index, 0);
    size = index;
    
    return result;
}

void print(Node* root) {
    if (root != nullptr) {
        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    
    Node* root = new Node(3);
    
    insert(root, 6);
    insert(root, 8);
    insert(root, 7);

    int depth = 2, size;

    int* elements = getElementsAtDepth(root, depth, size);

    cout << "Elements at depth " << depth << ": ";

    for (int i = 0; i < size; ++i) {
        cout << elements[i] << " ";
    }

    cout << endl;

    print(root);

    delete[] elements;
    deleteTree(root);

    return 0;
}