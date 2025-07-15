#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

/*
Разглеждаме дърво на директориите на файлова система. Всяка директория може да има произволен брой наследници.
Не се допускат две директории с едно и също име и общ пряк родител (в една директория не може да има две директории с едно и също име).
Всички възли имат име – символен низ с дължина не по-голяма от 12 символа, съставено от малки или главни латински букви, цифри, както и
символа точка. В тази задача не се изисква да се разглеждат други характеристики на директориите.
Корен на дървото винаги е главната директория. Тя е единственият елемент с празно име.
    • Да се опише структура, с която можете да се представи такова дърво и да се напише нейната дефиниция на C++.
    • Да се дефинира функция insert, която получава като аргументи дърво на файлова система и символен низ, описващ пълен път
    към директория, като за разделител се използва символът ’/’. Функцията трябва да добави тази директория в дървото, като при нужда
    създава всички липсващи родителски директории от пълния път до нея. Например, ако е зададен пълен път "/home/user/src", след приключване
    на работата на функцията в дървото със сигурност трябва да има елемент с име "home", който е наследник на корена; елемент с име "user",
    който е наследник на елемента "home", и елемент с име "src", който е наследник на елемента "user".
    • Да се дефинира функция flatten, която получава като аргумент дърво на файловата система и пълен път към елемент в него.
    Функцията трябва да преобразува всички непреки наследници на този елемент в негови преки наследници, т.е. всички елементи на поддървото
    на елемента трябва да станат преки наследници на корена му. Ако има повтарящи се имена, функцията трябва да остави само един пряк наследник
    с това име. Задачата трябва да се реализира на езика C++. Позволено е използването на класовете и методите от стандартната библиотека,
    отговаряща на стандарта C++14 или по-стар.
Пример: На първата фигура е показано примерно дърво на директориите. На следващата към това дърво е извършено добавяне на директорията
/home/usr/src/di. На последната е показан резултатът от прилагане на flatten към директорията /home на предходното дърво.
*/

struct Directory {
    string name;
    map<string, Directory*> children;

    Directory(const string& n) : name(n) {}
};

vector<string> splitPath(const string& path) {
    vector<string> parts;
    stringstream ss(path);
    string segment;

    while (getline(ss, segment, '/')) {
        if (!segment.empty()) {
            parts.push_back(segment);
        }
    }

    return parts;
}

void insert(Directory* root, const string& fullPath) {
    vector<string> parts = splitPath(fullPath);
    Directory* current = root;

    for (const string& name : parts) {
        if (current->children.find(name) == current->children.end()) {
            current->children[name] = new Directory(name);
        }

        current = current->children[name];
    }
}

Directory* findDirectory(Directory* root, const string& fullPath) {
    vector<string> parts = splitPath(fullPath);
    Directory* current = root;

    for (const string& name : parts) {
        auto it = current->children.find(name);

        if (it == current->children.end())
            return nullptr;

        current = it->second;
    }

    return current;
}

void flatten(Directory* root, const string& path) {
    Directory* dir = findDirectory(root, path);
    if (!dir) return;

    map<string, Directory*> newChildren;

    // DFS събиране на всички поддиректории
    vector<Directory*> stack;

    for (auto it = dir->children.begin(); it != dir->children.end(); ++it) {
        stack.push_back(it->second);
    }

    while (!stack.empty()) {
        Directory* current = stack.back();
        stack.pop_back();

        // само ако името още не е добавено
        if (newChildren.find(current->name) == newChildren.end()) {
            newChildren[current->name] = current;
        }

        for (auto it = current->children.begin(); it != current->children.end(); ++it) {
            stack.push_back(it->second);
        }
    }

    dir->children = newChildren;
}

void printTree(Directory* dir, int level = 0) {
    for (auto it = dir->children.begin(); it != dir->children.end(); ++it) {
        cout << string(level * 2, ' ') << "- " << it->first << '\n';
        printTree(it->second, level + 1);
    }
}

void deleteTree(Directory* dir) {
    if (!dir) return;

    for (auto it = dir->children.begin(); it != dir->children.end(); ++it) {
        deleteTree(it->second);
    }

    delete dir;
}

int main() {
    Directory* root = new Directory("");

    insert(root, "/home/user/docs");
    insert(root, "/home/user/src");
    insert(root, "/home/user/src/di");
    insert(root, "/home/guest/bin");
    insert(root, "/var/log");
    
    cout << "Преди flatten:\n";
    printTree(root);

    flatten(root, "/home");

    cout << "\nСлед flatten('/home'):\n";
    printTree(root);

    deleteTree(root);

    return 0;
}