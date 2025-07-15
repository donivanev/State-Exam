#include <iostream>
using namespace std;

/*
    • Да се дефинира подходяща индуктивна (рекурсивна) структура от данни, позволяваща представянето в паметта на програмата
    на възел на дърво от цели числа (int), за което всеки връх може да има произволен брой наследници (0, 1 или повече).
    • Да се дефинира рекурсивна функция (или статичен метод) [булев тип] member ([подходящ тип]root, int x) чиято стойност е
    истина точно тогава, когато в дървото с корен, представен от параметъра root, съществува възел със стойност x.
    • Да се дефинира рекурсивна функция (или статичен метод) void filterOdd ([подходящ тип] root), която премахва (чрез мутация)
    всяко поддърво t' на дървото с корен, представен от параметъра root, за което е изпълнено, че коренът на t' е със стойност
    нечетно число. На следната фигура е показано примерно дърво преди и след изпълнението на операцията filterOdd.
*/

struct TreeNode {
    int data;
    TreeNode *firstChild, *nextSibling;

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

bool member(TreeNode* root, int x) {
    if (!root) {
        return false;
    }

    if (root->data == x) {
        return true;
    }
    
    return member(root->firstChild, x) || member(root->nextSibling, x);
}

void deleteSubtree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteSubtree(root->firstChild); // Recursively delete all children
    deleteSubtree(root->nextSibling); // Recursively delete all siblings

    delete root;
}

void filterOdd(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    filterOdd(root->firstChild);
    filterOdd(root->nextSibling);

    // If the current node has an odd value, remove this node
    if (root->data % 2 != 0) {
        TreeNode* temp = root->nextSibling; // Save the pointer to the next sibling

        deleteSubtree(root); // Delete the current subtree starting from this node

        root = temp; // Set the current node to the next sibling
    }
}

void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < level; i++) {
        cout << "  ";  // Indent based on the level of the tree
    }

    cout << root->data << endl;
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->firstChild = new TreeNode(3);
    root->firstChild->nextSibling = new TreeNode(5);
    root->firstChild->firstChild = new TreeNode(4);
    root->firstChild->firstChild->nextSibling = new TreeNode(8);
    root->firstChild->nextSibling->firstChild = new TreeNode(7);

    //        10
    //       /  \
    //      3    5
    //     / \    \
    //    4   8    7

    cout << "Original Tree:" << endl;
    printTree(root);

    int x = 8;
    
    member(root, x) ? cout << "Value " << x << " is present in the tree." << endl :
                      cout << "Value " << x << " is not present in the tree." << endl;

    filterOdd(root);

    cout << "\nTree after filtering odd numbers:" << endl;
    printTree(root);

    deleteSubtree(root);

    return 0;
}