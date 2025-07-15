#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

/*
Троично дърво от латински букви ще наричаме следната структура:
    - Празното дърво е троично дърво от латински букви;
    - Ако Т1, Т2 и Т3 са троични дървета от латински букви, а x е латинска буква, то наредената четворка <x, Т1, Т2, Т3> също
    е троично дърво от латински букви.
а) Да се напише функция readLast, която по дадено троично дърво от латински букви намира думата, която може да се прочете
отляво надясно в последното му ниво. Ниво на троично дърво от латински букви наричаме списък от възли в дървото, които са
равноотдалечени от корена.
Пример: за дървото вдясно функцията readLast трябва да връща думата "cat".
Представянето на дървото е по Ваш избор. Опишете избраното от Вас представяне.
б) Да се напише функция serialize, която по дадени: (1) троично дърво от латински букви и (2) низ, описващ път до файл, записва
дървото в текстов файл. Текстовото представяне на троично дърво да бъде следното:
    - Текстовото представяне на празното дърво е звездичка ("*");
    - Текстовото представяне на троичното дърво <x, Т1, Т2, Т3> е "(x T1 T2 T3)", където T1, T2 и T3 са текстовите представяния
    съответно на Т1, Т2 и Т3.
Пример: Текстовото представянето на дървото горе е:
(b (x (p * * *) (q * * *) (r (c * * *) * (a * * *))) (y * * (s * (t * * *) *)) *)
За реализацията на функциите readLast и serialize е позволено използването на стандартните за съответния език библиотечни функции.
*/

struct TriNode {
    char value;
    TriNode* left;
    TriNode* middle;
    TriNode* right;

    TriNode(char v) : value(v), left(nullptr), middle(nullptr), right(nullptr) {}
};

string readLast(TriNode* root) {
    if (!root) return "";

    queue<TriNode*> q;
    q.push(root);

    vector<char> lastLevel;

    while (!q.empty()) {
        int levelSize = q.size();
        lastLevel.clear();  // ще се презаписва на всяко ново ниво

        for (int i = 0; i < levelSize; ++i) {
            TriNode* node = q.front(); q.pop();
            lastLevel.push_back(node->value);

            if (node->left)   q.push(node->left);
            if (node->middle) q.push(node->middle);
            if (node->right)  q.push(node->right);
        }
    }

    return string(lastLevel.begin(), lastLevel.end());
}

void serializeHelper(ofstream& out, TriNode* node) {
    if (!node) {
        out << "*";
        return;
    }

    out << "(" << node->value << " ";
    serializeHelper(out, node->left);
    out << " ";
    serializeHelper(out, node->middle);
    out << " ";
    serializeHelper(out, node->right);
    out << ")";
}

void serialize(TriNode* root, const string& filePath) {
    ofstream out(filePath);

    if (!out) {
        cerr << "Неуспешно отваряне на файл\n";
        return;
    }

    serializeHelper(out, root);
    out.close();
}

int main() {
    // Примерно дърво (b ... )
    TriNode* root = new TriNode('b');
    root->left = new TriNode('x');
    root->left->left = new TriNode('p');
    root->left->middle = new TriNode('q');
    root->left->right = new TriNode('r');
    root->left->right->left = new TriNode('c');
    root->left->right->right = new TriNode('a');

    root->middle = new TriNode('y');
    root->middle->right = new TriNode('s');
    root->middle->right->middle = new TriNode('t');

    cout << "Последно ниво: " << readLast(root) << endl;

    serialize(root, "tree.txt");

    return 0;
}