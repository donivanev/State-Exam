#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Разглеждаме двоично дърво с данни от тип символ и елементи, описвани от следната структура:

struct Node {
    char text;
    Node *left, *right;
};

Стойностите са малки и главни латински букви, цифри и препинателни знаци. Няма празни символи (интервал, нов ред, табулация)
и символи от разширената ASCII таблица (с код по-голям от 127). Пример за такова дърво е:

Да се реализира функция printText, която получава като аргумент указател към корен на такова дърво и извежда на стандартния
изход текста, записан във върховете, спазвайки следните правила:
  • съдържанието на всяко ниво (елементи с еднаква дълбочина) се извежда на отделен ред;
  • ако на дадено място в нивото липсва възел, да се изведе интервал;
  • дървото се извежда до последния елемент от последното ниво.

За показаното като пример дърво трябва да се изведе следния текст:
|I|
|am|
|good|
|at␣solvi|
|ng␣p␣␣roblem␣␣␣␣|
|s␣␣!|
Забележка: за яснота на примера в началото и края на всеки ред е добавен символът pipe |, който printText не трябва да извежда.
Да се демонстрира работата на тази функция в кратка програма.
Забележка: позволено е използването на класовете контейнери от стандартната библиотека STL.
*/

struct Node {
    char text;
    Node *left, *right;

    Node(char t) : text(t), left(nullptr), right(nullptr) {}
};

// Връща височината на дървото
int height(Node* root) {
    if (!root)
        return 0;
    
    return 1 + max(height(root->left), height(root->right));
}

void printText(Node* root) {
    if (!root)
        return;

    queue<Node*> q;
    q.push(root);

    int levels = height(root);

    for (int level = 0; level < levels; ++level) {
        int nodesInLevel = 1 << level; // 2^level възела
        vector<Node*> current;

        for (int i = 0; i < nodesInLevel; ++i) {
            if (!q.empty()) {
                Node* node = q.front();
                q.pop();
                current.push_back(node);

                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    // запазваме място за липсващи деца
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
        }

        // Печат на текущото ниво
        for (Node* node : current) {
            node ? cout << node->text : cout << ' ';
        }

        cout << endl;
    }
}

void deleteTree(Node* root) {
    if (!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    /*
                I
              /   \
             a     m
            / \   / \
           g  o  o   d
          / \      /  \
         a   t    s    o
        / \         \
       l   v         !
    */

    Node* root = new Node('I');
    root->left = new Node('a');
    root->right = new Node('m');
    root->left->left = new Node('g');
    root->left->right = new Node('o');
    root->right->left = new Node('o');
    root->right->right = new Node('d');
    root->left->left->left = new Node('a');
    root->left->left->right = new Node('t');
    root->right->right->left = new Node('s');
    root->right->right->right = new Node('o');
    root->left->left->left->left = new Node('l');
    root->left->left->left->right = new Node('v');
    root->right->right->left->right = new Node('!');

    printText(root);
    deleteTree(root);

    return 0;
}