#include <iostream>
#include <vector>
using namespace std;

/*
Разглеждаме (кореново) дърво с върхове, чиито стойности са цели числа, като всеки връх може да има произволен брой наследници,
редът на които ще има значение – първия ще наричаме най-ляв, а последния – най-десен. "Ниво с номер 𝑛" наричаме списък от
върховете в дървото, които са на разстояние 𝑛 от корена, подредени от ляво надясно. Казваме, че ниво в дървото "представя" даден
вектор от цели числа, ако елементите във върховете в нивото образуват точно елементите на вектора.
А) Да се дефинира тип TreeNode за представяне на връх от такова дърво.
Б) Да се реализира функция int findLevel(const TreeNode* root, const vector<int>& numbers); която по подаден указател към корен
на такова дърво намира номер на ниво, представящо вектора numbers, или -1, ако такова ниво няма. Ако има повече от едно ниво с
такива елементи, не е от значение кой номер ще се върне. Приемаме, че коренът определя ниво с номер 0.
В) Да се реализира функция void removeAllLevels(TreeNode* root, const vector<int>& numbers) която по подаден указател към корен
на дърво премахва всички нива с положителен номер, които представят вектора numbers. При премахване на връх, неговите преки
наследници заемат неговото място и стават преки наследници на родителя му. Приемаме, че елементите на дървото са заделени с new.
Позволено е използването на всички средства от стандартната библиотека на C/C++.
Пример: За дървото вляво и вектор от числа { 1, 2, 8, 6 }, функцията findLevel трябва да върне 2, а след изпълнението на
removeAllLevels трябва да се получи дървото вдясно.
*/

struct TreeNode {
    int value;
    vector<TreeNode*> children;

    TreeNode(int v) : value(v) {}
};

int findLevel(const TreeNode* root, const vector<int>& numbers) {
    if (!root) return -1;

    vector<const TreeNode*> currentLevel = { root };
    int level = 0;

    while (!currentLevel.empty()) {
        vector<int> values;
        vector<const TreeNode*> nextLevel;

        for (const TreeNode* node : currentLevel) {
            values.push_back(node->value);

            for (const TreeNode* child : node->children)
                nextLevel.push_back(child);
        }

        if (values == numbers)
            return level;

        currentLevel = nextLevel;
        ++level;
    }

    return -1;
}

void removeAllLevels(TreeNode* root, const vector<int>& numbers) {
    if (!root) return;

    vector<TreeNode*> currentLevel = { root };
    int level = 0;

    while (!currentLevel.empty()) {
        vector<TreeNode*> nextLevel;
        vector<int> values;

        for (TreeNode* node : currentLevel) {
            for (TreeNode* child : node->children)
                values.push_back(child->value);
        }

        // проверка за съвпадение
        bool match = (level > 0 && values == numbers);

        for (TreeNode* node : currentLevel) {
            vector<TreeNode*> newChildren;

            for (TreeNode* child : node->children) {
                if (match) {
                    // премахваме child, закачаме неговите деца
                    for (TreeNode* grandChild : child->children)
                        newChildren.push_back(grandChild);
                    delete child; // освобождаваме child
                } else {
                    newChildren.push_back(child);
                }
            }

            node->children = newChildren;
        }

        // събираме следващото ниво
        for (TreeNode* node : currentLevel) {
            for (TreeNode* child : node->children)
                nextLevel.push_back(child);
        }

        currentLevel = nextLevel;
        ++level;
    }
}

void printTree(TreeNode* node, int depth = 0) {
    if (!node)
        return;
    
    cout << string(depth * 2, ' ') << node->value << '\n';
    
    for (TreeNode* child : node->children)
        printTree(child, depth + 1);
}

int main() {
    // Примерно дърво:
    //       0
    //     / | \
    //    1  2  3
    //   /       \
    //  8         6

    TreeNode* root = new TreeNode(0);

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    root->children = {n1, n2, n3};

    TreeNode* n8 = new TreeNode(8);
    TreeNode* n6 = new TreeNode(6);

    n1->children.push_back(n8);
    n3->children.push_back(n6);

    cout << "Преди:\n";
    printTree(root);

    vector<int> pattern = {1, 2, 3};
    int level = findLevel(root, pattern);
    cout << "\nНиво със стойности {1,2,3} е: " << level << '\n';

    vector<int> removePattern = {8, 6};
    removeAllLevels(root, removePattern);

    cout << "\nСлед премахване на {8,6}:\n";
    printTree(root);

    return 0;
}