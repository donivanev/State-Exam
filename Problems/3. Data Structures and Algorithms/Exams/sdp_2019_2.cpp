#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Дърво с етикети ще наричаме кореново дърво T = (V , E, r) с множество от върхове V, множество от ребра E и корен r, за което са дефинирани
две допълнителни функции:
    • value ∶ E → {n ∈ ℕ | 0 ≤ n < 2}
    • label ∶ E → {a, b, ..., z}
Клон в T ще наричаме път 𝜋 = (𝑣₀, 𝑣₁, ... , 𝑣ₙ), за който 𝑣ₙ е листо на T и 𝑣ᵢ е родител на 𝑣ᵢ₊₁ за всяко 𝑖 < 𝑛.
За всеки клон 𝜋 = (𝑣₀, 𝑣₁, ... , 𝑣ₙ) дефинираме:
    • 𝑣𝑎𝑙(𝜋) = ∑ᵢ₌₀ 𝑣𝑎𝑙𝑢𝑒(<𝑣ᵢ, 𝑣ᵢ₊₁>) и 𝑤𝑜𝑟𝑑(𝜋) = label(<𝑣₀, 𝑣₁>)label(<𝑣₁, 𝑣₂>)...label(<𝑣ᵢ, 𝑣ᵢ₊₁>)
А) Да се избере, дефинира и опише подходящо представяне на дърво от описания вид.
Б) За така дефинираното представяне да се реализира функцията: CommonBranches(<labeled tree> T, <vertex> u, <vertex> v, <integer> k),
която по дадено дърво с етикети T = (V , E, r), два негови върха u и v и естествено число k извежда на стандартния изход всички думи w,
за които има клони 𝜋ᵤ и 𝜋ᵥ с начало u и съответно v, за които 𝑤𝑜𝑟𝑑(𝜋ᵤ) = 𝑤𝑜𝑟𝑑(𝜋ᵥ) = w и 𝑣𝑎𝑙(𝜋ᵤ) + 𝑣𝑎𝑙(𝜋ᵥ) = k.
Забележки:
• Отделните думи да са разделени със символа за нов ред. Една дума може да се извежда повече от веднъж.
• Функционалности на структурата дърво с етикети, които нямат отношение към задачата и не се използват във функцията CommonBranches, няма да бъдат оценявани.
*/

struct Node; // предварителна декларация

struct Edge {
    char label;      // буква a-z
    int value;       // 0 или 1
    Node* child;     // към кой възел сочи
};

struct Node {
    vector<Edge> children;
};

struct PathInfo {
    string word;
    int sum;
};

void collectPaths(Node* node, string currentWord, int currentSum, vector<PathInfo>& out) {
    if (!node)
        return;

    if (node->children.empty()) {
        out.push_back({currentWord, currentSum});
        return;
    }

    for (const Edge& edge : node->children) {
        collectPaths(edge.child, currentWord + edge.label, currentSum + edge.value, out);
    }
}

void CommonBranches(Node* u, Node* v, int k) {
    vector<PathInfo> pathsU, pathsV;
    collectPaths(u, "", 0, pathsU);
    collectPaths(v, "", 0, pathsV);

    for (const auto& pu : pathsU) {
        for (const auto& pv : pathsV) {
            if (pu.word == pv.word && pu.sum + pv.sum == k) {
                cout << pu.word << endl;
            }
        }
    }
}

int main() {
    // Създаваме възел u и v с по еднакъв път: a -> b -> c
    Node* u = new Node();
    Node* u1 = new Node();
    Node* u2 = new Node();

    u->children.push_back({'a', 1, u1});
    u1->children.push_back({'b', 0, u2});
    u2->children.push_back({'c', 1, new Node()});

    Node* v = new Node();
    Node* v1 = new Node();
    Node* v2 = new Node();

    v->children.push_back({'a', 0, v1});
    v1->children.push_back({'b', 1, v2});
    v2->children.push_back({'c', 0, new Node()});

    // Пътища: abc със суми: u → 1 + 0 + 1 = 2, v → 0 + 1 + 0 = 1 → общо 3
    cout << "Съвпадащи думи със стойност 3:\n";
    CommonBranches(u, v, 3);

    return 0;
}