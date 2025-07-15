#include <iostream>
#include <cstring>
using namespace std;

/*
Да се състави функция, която приема като параметър низ с произволна дължина и връща като резултат позициите на двойката еднакви
символи, които са максимално отдалечени един от друг. Ако в низа съществуват няколко двойки максимално отдалечени символи,
функцията да връща позициите на най-ляво разположената двойка. Счита се, че номерата на позициите започват от 0.
Пример:
В символния низ "this is just a simple example" най-ляво и най-дясно разположените символи ' ' (интервали), са на позиции
съответно 4 и 21, намират се на разстояние 17 символа един от друг и няма друга двойка еднакви символи, които са на по-голямо
разстояние един от друг.
*/

void getMaxDistEqualSymbols(char* s) {
    int n = strlen(s);
    int* firstPositions = new int[n]{0};
    int* secondPositions = new int[n]{0};
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                cout << i << " and " << j << endl;
                firstPositions[index] = i;
                secondPositions[index] = j;
                index++;
            }
        }
    }

    int maxAbsPositions = 0, resultI = 0, resultJ = 0;

    for (int i = 0; i < n; i++) {
        if (abs(firstPositions[i] - secondPositions[i]) > maxAbsPositions) {
            maxAbsPositions = abs(firstPositions[i] - secondPositions[i]);
            resultI = firstPositions[i];
            resultJ = secondPositions[i];
        }
    }

    cout << resultI << " " << resultJ;
}

int main() {

    char* str = new char[100];

    cin.get(str, 50);
    cout << str;

    getMaxDistEqualSymbols(str);

    delete[] str;

    return 0;
}