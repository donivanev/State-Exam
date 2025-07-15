#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_LINE_LEN = 500, MAX_WORDS = 50, MAX_WORD_LEN = 100;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Заделяне на памет за масив от указатели към думи
char** allocatememory(int max_words) {
    char** words = new char*[max_words];

    for (int i = 0; i < max_words; i++) {
        words[i] = nullptr; // ще заделим всяка дума отделно при четене
    }

    return words;
}

// Чете един ред, разбива го на думи, и запазва всяка дума динамично
int readtext(char** words, int max_words, int max_word_len) {
    char buffer[MAX_LINE_LEN];
    cin.getline(buffer, MAX_LINE_LEN);

    int word_count = 0, i = 0;

    while (buffer[i] != '\0' && word_count < max_words) {
        while (buffer[i] == ' ')
            i++;
        if (buffer[i] == '\0')
            break;

        char temp[max_word_len];
        int j = 0;
        
        while (buffer[i] != '\0' && buffer[i] != ' ' && j < max_word_len - 1) {
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

    const int max_words = MAX_WORDS, max_word_len = MAX_WORD_LEN;

    char** words = allocatememory(max_words);
    int word_count = readtext(words, max_words, max_word_len);

    printwords(words, word_count);
    deallocatememory(words, word_count);

    return 0;
}