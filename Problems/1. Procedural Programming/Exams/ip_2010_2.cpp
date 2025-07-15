#include <iostream>
using namespace std;

/*
Дума в текст е всяка редица от малки и големи латински букви, цифри или символа '_'. Всички останали символи се считат за препинателни знаци.
Да се напише функция, която преобразува текст по следния начин:
    • редицата от думи в текста се обръща в обратен ред като първата дума става последна, втората дума става предпоследна и т.н.,
    последната дума става първа.
    • редицата от препинателни знаци в текста остава същата. Това означава, че ако има препинателен знак след първата дума на входния текст,
    то след преобразуването този препинателен знак е след последната дума от входния текст, която дума е първа в изходния текст.
    • думите запазват реда на буквите си.
    • препинателните знаци, ако са повече от един между две думи, също запазват реда си.

Примери.
Вход: текст 1.
Изход: 1 текст.
Входният текст съдържа две думи: "текст" и "1", а препинателните знаци са ' ' и '.'.
В изхода думите сменят реда си, а препинателните знаци остават на местата си.

Вход: текст !
Изход: текст !
Текстът "текст !" не се променя тъй като се състои само от една дума.

Вход: 1;;2;3;4;;5.
Изход: 5;;4;3;2;;1.
Входният текст съдържа пет думи: "1", "2", "3", "4" и "5" и препинателните знаци: ';' и '.'. 
*/

const int MAX_LINE_LEN = 1000;
const int MAX_WORDS = 500;
const int MAX_WORD_LEN = 100;

// Заделяне на памет за масив от указатели към думи
char** allocatememory(int max_words) {
    char** words = new char*[max_words];

    for (int i = 0; i < max_words; i++) {
        words[i] = nullptr; // ще заделим всяка дума отделно
    }

    return words;
}

// Чете един ред, разбива го на думи и запазва всяка дума динамично
int readtext(char** words, int max_words) {
    char buffer[MAX_LINE_LEN];
    cin.getline(buffer, MAX_LINE_LEN);

    int word_count = 0;
    int i = 0;

    while (buffer[i] != '\0' && word_count < max_words) {
        // Случай, в който има интервали в началото на изречението
        while (buffer[i] == ' ')
            i++;
        if (buffer[i] == '\0')
            break;

        char temp[MAX_WORD_LEN]; // буфер за текущата дума
        int j = 0;

        while (buffer[i] != '\0' && buffer[i] != ' ' && j < MAX_WORD_LEN - 1) {
            temp[j++] = buffer[i++];
        }

        temp[j] = '\0';

        words[word_count] = new char[j + 1];

        for (int k = 0; k <= j; k++) {
            words[word_count][k] = temp[k];
        }

        word_count++;
    }

    return word_count;
}

// Извежда всички думи (по подразбиране — в оригиналния ред)
void printwords(char** words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
}

// Освобождаване на памет
void deallocatememory(char** words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        delete[] words[i];
    }
    delete[] words;
}

int main() {

    int max_length = 50;
    char** words = allocatememory(max_length);
    int word_count = readtext(words, max_length);

    printwords(words, max_length);
    deallocatememory(words, max_length);

    return 0;
}