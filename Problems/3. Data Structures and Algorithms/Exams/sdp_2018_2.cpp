#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

/*
Нека разгледаме следната структура от данни за бързо търсене, съхраняваща сортирана редица от цели числа:
Имаме списък с n елемента и нека с k означим горната цяла част на числото √𝑛. Всеки възел на списъка съдържа цяло число и два указателя.
Първият указател винаги сочи следващия елемент (ако има такъв). За възлите, намиращи се на индекс, кратен на k, вторият указател сочи възела,
намиращ се на k позиции напред (ако има такъв). В горния пример n = 9, k = 3.
а) Да се напише функция readList, която по подаден път до текстов файл прочита от файла сортирана редица от цели числа и конструира списък от
описания по-горе тип, съдържащ прочетените числа. Числата са записани във файла на един ред и са разделени с интервали.
б) Да се напише булева функция member, която по даден списък от описания тип и дадено цяло число проверява дали това число се съдържа в списъка.
Функцията да реализира ефективен алгоритъм за търсене, който се възползва от особеностите на структурата, за да минимизира броя на обходените елементи.
Пример: ако в списъка от диаграмата по-горе търсим числото 6, при ефективния алгоритъм за търсене ще бъдат последователно обходени следните елементи:
1, 4, 7, 5, 6 и функцията member ще върне резултат "истина".
За реализацията на гореописаната структура от данни и за функциите readList и member не е позволено използване на библиотечни структури от данни и
алгоритми, но е позволено използването на стандартните функции за работа с файлове.
*/

struct Node {
    int data;
    Node* next;
    Node* jump;

    Node(int val) : data(val), next(nullptr), jump(nullptr) {}
};

// Прочита списък от файл и изгражда структурата
Node* readList(const string& path) {
    ifstream file(path);

    if (!file) {
        cerr << "Неуспешно отваряне на файл\n";
        return nullptr;
    }

    string line;
    getline(file, line);
    file.close();

    istringstream iss(line);
    int val;
    Node* head = nullptr;
    Node* tail = nullptr;

    vector<Node*> nodes;

    while (iss >> val) {
        Node* node = new Node(val);
        nodes.push_back(node);

        if (!head) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    int n = nodes.size();
    int k = ceil(sqrt(n));

    for (int i = 0; i < n; ++i) {
        if (i % k == 0 && i + k < n) {
            nodes[i]->jump = nodes[i + k];
        }
    }

    return head;
}

bool member(Node* head, int target) {
    Node* curr = head;

    while (curr) {
        cout << "Visited: " << curr->data << endl;
        
        if (curr->data == target)
            return true;

        // Ако jump е валиден и ни доближава до целта
        if (curr->jump && curr->jump->data <= target) {
            curr = curr->jump;
        } else {
            curr = curr->next;
        }
    }

    return false;
}

int main() {
    Node* list = readList("numbers.txt");

    int x;
    cout << "Търсене на число: ";
    cin >> x;

    if (member(list, x))
        cout << "Числото " << x << " се съдържа в списъка.\n";
    else
        cout << "Числото " << x << " НЕ се съдържа в списъка.\n";

    return 0;
}