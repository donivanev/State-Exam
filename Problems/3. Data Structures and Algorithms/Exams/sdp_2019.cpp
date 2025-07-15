#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Разглеждаме кореново дърво, във възлите на което има записани двойки от символ (char) и цяло число (int). Всеки възел на
дървото може да има произволен, краен брой наследници. За удобство разглеждаме функциите 𝑠𝑦𝑚 и 𝑣𝑎𝑙, дефинирани над множеството
от възлите на дървото, така че за всеки възел 𝑣 на дървото, в който е записана двойката <𝑎, 𝑏>, 𝑠𝑦𝑚(𝑣) = 𝑎 и 𝑣𝑎𝑙(𝑣) = 𝑏.
Клон в дървото T ще наричаме всеки път 𝜋 = (𝑣₀, 𝑣₁, ..., 𝑣ₙ), за който 𝑣₀, ..., 𝑣ₙ са върхове на T, 𝑣ₙ е листо на T, а
𝑣ᵢ е родител на 𝑣ᵢ₊₁ за всяко 𝑖 < 𝑛.
За всеки клон 𝜋 = (𝑣₀, 𝑣₁, ..., 𝑣ₙ) на дървото T дефинираме съответни "дума" и "стойност" по следния начин:
    • 𝑤𝑜𝑟𝑑(𝜋) = 𝑠𝑦𝑚(𝑣₀)𝑠𝑦𝑚(𝑣₁)...𝑠𝑦𝑚(𝑣ₙ), 𝑣𝑎𝑙𝑢𝑒(𝜋) = ∑ᵢ₌₀ 𝑣𝑎𝑙(𝑣ᵢ), т.е. 𝑤𝑜𝑟𝑑(𝜋) е думата, която се получава от последователното
прочитане на символите, записани във възлите на пътя, а 𝑣𝑎𝑙𝑢𝑒(𝜋) е сумата на числата, записани в тях.
а) Да се избере, дефинира и опише подходящо представяне на дърво от описания тип.
б) За така дефинираното представяне да се реализира функцията: int sumVal ([подходящ тип] T, [подходящ тип] u, [подходящ тип] v),
която по дадено дърво T и два негови върха 𝑢 и 𝑣 намира и връща сумата от всички стойности 𝑣𝑎𝑙𝑢𝑒(𝜋ᵤ) + 𝑣𝑎𝑙𝑢𝑒(𝜋ᵥ), за които 𝜋ᵤ и 𝜋ᵥ
са клони с начала 𝑢 и 𝑣 (съответно) със свойството 𝑤𝑜𝑟𝑑(𝜋ᵤ) = 𝑤𝑜𝑟𝑑(𝜋ᵥ). Ако такива клони няма, сумата се счита за 0.
Забележки:
    1. В зависимост от избраното представяне, параметърът T може да бъде пропуснат.
    2. Не е нужно дефиницията на представянето на дървото да бъде пълна, а само да е достатъчна за реализацията на функцията sumVal.
    3. Позволено е използването на функциите и класовете от стандартната библиотека на C++
*/

struct Node {
    char sym;               // символ (буква)
    int val;                // стойност
    vector<Node*> children; // произволен брой наследници

    Node(char s, int v) : sym(s), val(v) {}
};

struct Path {
    string word;
    int sum;
};

void collectPaths(Node* node, string currentWord, int currentSum, vector<Path>& paths) {
    if (!node) return;

    currentWord += node->sym;
    currentSum += node->val;

    if (node->children.empty()) {
        paths.push_back({currentWord, currentSum});
    }
    else {
        for (Node* child : node->children) {
            collectPaths(child, currentWord, currentSum, paths);
        }
    }
}

int sumVal(Node* u, Node* v) {
    vector<Path> pathsU, pathsV;
    collectPaths(u, "", 0, pathsU);
    collectPaths(v, "", 0, pathsV);

    int total = 0;

    for (const Path& pu : pathsU) {
        for (const Path& pv : pathsV) {
            if (pu.word == pv.word) {
                total += pu.sum + pv.sum;
            }
        }
    }

    return total;
}

int main() {
    // Създаваме малко примерно дърво:

    //     a(1)
    //    /     \
    //  b(2)    b(3)
    //   |        \
    //  c(4)      c(5)

    Node* root = new Node('a', 1);

    Node* b1 = new Node('b', 2);
    Node* b2 = new Node('b', 3);

    Node* c1 = new Node('c', 4);
    Node* c2 = new Node('c', 5);

    root->children.push_back(b1);
    root->children.push_back(b2);

    b1->children.push_back(c1);
    b2->children.push_back(c2);

    // Пътищата: abc(7), abc(9) => word = "abc" → sum = 7 + 9 = 16
    cout << "Сума: " << sumVal(b1, b2) << endl;  // Изход: 16

    return 0;
}