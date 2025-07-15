#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Да се напише функция, която получава като параметри цяло число K и едномерен масив A с елементи различни цели числа.
Функцията трябва да построи в паметта дърво T, съдържащо данните в масива A, като дървото T трябва да удовлетворява следните условия:
    • Всеки елемент на A се среща като възел в T точно веднъж.
    • Всеки възел в T има най-много K преки наследници (деца).
    • T е с възможно най-малка дълбочина.
    • Ако i < j, то A[i] да не се намира по-дълбоко от A[j] в T (т.е. да е на същата или по-малка дълбочина).
Като резултат функцията да връща построеното дърво и да извежда на стандартния изход неговата дълбочина.
Конкретното представяне на дървото в паметта е по Ваш избор.
Пример: За A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} и K = 3, минималната дълбочина е 3, а едно дърво T, удовлетворяващо горните условия, е:
           1
         / | \
        /  |  \ 
       /   |   \
      2    3     4
     / \   |   / | \
    5   7  9  8 10  6
*/

struct Node {
    int data;
    vector<Node*> children;
    Node(int val) : data(val) {}
};

// Функцията връща корена и отпечатва дълбочината
Node* buildTree(const vector<int>& A, int K, int& outDepth) {
    if (A.empty()) {
        outDepth = 0;
        return nullptr;
    }

    Node* root = new Node(A[0]);
    queue<Node*> q;
    q.push(root);
    size_t index = 1;
    int depth = 1;

    while (index < A.size()) {
        int levelSize = q.size(); // брой възли на текущото ниво
        bool added = false;

        for (int i = 0; i < levelSize && index < A.size(); ++i) {
            Node* parent = q.front();
            q.pop();

            for (int j = 0; j < K && index < A.size(); ++j) {
                Node* child = new Node(A[index++]);
                parent->children.push_back(child);
                q.push(child);
                added = true;
            }
        }

        if (added)
            ++depth;
    }

    outDepth = depth;
    return root;
}

void printTreeByLevels(Node* root) {
    if (!root)
        return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front(); q.pop();
            cout << current->data << " ";
            
            for (Node* child : current->children)
                q.push(child);
        }

        cout << endl;
    }
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 3;
    int depth = 0;

    Node* root = buildTree(A, K, depth);

    cout << "Минимална дълбочина: " << depth << endl;
    cout << "Дървото по нива:\n";
    printTreeByLevels(root);

    return 0;
}