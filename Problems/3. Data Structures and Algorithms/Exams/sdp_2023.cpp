#include <iostream>
using namespace std;

/*
Троично дърво ще наричаме наредено дърво, за което всеки възел съхранява една или две стойности и има не повече от три наследника.
Ако за произволен възел означим стойностите на двата елемента в него с X и Y, а трите негови потенциални поддървета с STleft,
STmid и STright, то за да е валидно такова дърво, трябва да са в сила следните свойства:
    • стойността X трябва да е строго по-малка от стойността Y;
    • стойността на всеки елемент от поддървото STleft трябва да е строго по-малка от X;
    • стойността на всеки елемент от поддървото STmid трябва да е по-голяма или равна на X и строго по-малка от Y;
    • стойността на всеки елемент от поддървото STright трябва да е по-голяма или равна на Y;
    • ако в даден възел няма втора стойност (Y), то тогава поддървото STright задължително трябва да е празно;
    • ако в поддървото STmid на даден възел има поне един елемент по-голям от X, то във възела задължително трябва да има две
    стойности (X и Y);
    • всяко от STleft, STmid и STright или е празно, или е валидно троично дърво.
Така неформално можем да напишем следното неравенство: STleft < X ≤ STmid < Y ≤ STright. Пример за такова дърво е:
       5|10
      /  |  \
    2|3 5|7 12|
    /  \
    0|1 3|4

1) Да се опише структура, с която може да се представи такова троично дърво с елементи цели числа и да се напише нейната
дефиниция на C++.
2) Да се дефинира функция insert с аргументи троично дърво от цели числа и цяло число, която добавя това число в дървото,
съблюдавайки изискванията за валидност. При добавяне на нова стойност не трябва да се променят или преместват съществуващите
в дървото стойности.
3) Да се дефинира функция find с аргументи троично дърво от цели числа и цяло число, която проверява дали подаденото число се
съдържа в дървото.
4) Да се реализира кратка програма, която демонстрира описаните функции, като за целта:
    а) създава празно дърво;
    б) въвежда от стандартния вход естествено число N, последвано от N цели числа, които добавя в дървото;
    в) прочита от стандартния вход едно число и извежда на стандартния изход подходящ текст, указващ дали това число се среща
    или не в дървото;
    г) подсигурява коректна работа с паметта.
*/

struct TernaryNode {
    int x;              // първата стойност (задължителна)
    int y;              // втората стойност (може да липсва)
    bool hasY;          // флаг дали y е валиден

    TernaryNode* left;
    TernaryNode* mid;
    TernaryNode* right;

    TernaryNode(int val) : x(val), hasY(false), y(0), left(nullptr), mid(nullptr), right(nullptr) {}
};

void insert(TernaryNode*& root, int val) {
    if (!root) {
        root = new TernaryNode(val);
        return;
    }

    if (!root->hasY) {
        if (val == root->x)
            return; // без дубли
        if (val < root->x) {
            insert(root->left, val);
        }
        else {
            // ако ще има поне едно число > x → разрешено е да стане x|val
            root->y = val;
            root->hasY = true;
        }
    } 
    else {
        if (val == root->x || val == root->y) 
            return;

        if (val < root->x) {
            insert(root->left, val);
        }
        else if (val < root->y) {
            insert(root->mid, val);
        }
        else {
            insert(root->right, val);
        }
    }
}

bool find(TernaryNode* root, int val) {
    if (!root)
        return false;
    if (val == root->x || (root->hasY && val == root->y))
        return true;

    if (val < root->x)
        return find(root->left, val);
    else if (!root->hasY || val < root->y)
        return find(root->mid, val);
    else
        return find(root->right, val);
}

void deleteTree(TernaryNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->mid);
    deleteTree(root->right);
    delete root;
}

int main() {
    TernaryNode* tree = nullptr;

    int N;
    cout << "Въведи брой елементи: ";
    cin >> N;

    cout << "Въведи " << N << " цели числа: ";
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        insert(tree, val);
    }

    int query;
    cout << "Число за търсене: ";
    cin >> query;

    if (find(tree, query))
        cout << "Числото се среща в дървото.\n";
    else
        cout << "Числото НЕ се среща в дървото.\n";

    deleteTree(tree); // почистване на паметта

    return 0;
}