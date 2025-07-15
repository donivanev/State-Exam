#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

/*
Да се напише функция, която по зададен масив от низове намира най-големия брой низове от масива, които са анаграми помежду си.
Един низ е анаграма на друг, ако е съставен от същите символи, но в разбъркан ред, като това означава, че за да са анаграми два низа
трябва всеки от символите на първия да се среща точно толкова пъти и във втория. Например низовете asdff и fsdaf са анаграми един на друг,
докато низовете asdff и ааfsd не са.

Примери:
    Вход: string ginrts ringst strong spong shpong pongs
    Изход: 3
Думите могат да бъдат разделени на следните групи, елементите на които са анаграми помежду си:
string ginrts ringst
strong
shpong
spong pongs
*/

// Bubble sort на символите в низ
void sortChars(char* str) {
    int len = strlen(str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

// Разделя входния низ на отделни думи и ги запазва в динамична матрица
int splitToWords(const char* input, char*** wordsOut) {
    int count = 0;
    int i = 0;

    // Преброяване на думите
    while (input[i]) {
        while (input[i] == ' ')
            i++;
        if (input[i] == '\0')
            break;
        
        count++;
        
        while (input[i] != ' ' && input[i] != '\0')
            i++;
    }

    char** words = new char*[count];
    i = 0;
    int index = 0;

    while (input[i]) {
        while (input[i] == ' ')
            i++;
        if (input[i] == '\0')
            break;

        // Четене на дума в buffer
        char buffer[100];
        int j = 0;

        while (input[i] != ' ' && input[i] != '\0') {
            buffer[j++] = input[i++];
        }

        buffer[j] = '\0';

        words[index] = new char[j + 1];
        strcpy(words[index], buffer);
        index++;
    }

    *wordsOut = words;
    return count;
}

int maxAnagramGroup(const char* input) {
    char** words;
    int count = splitToWords(input, &words);

    // Създаваме сортирани копия на думите
    char** normalized = new char*[count];
    
    for (int i = 0; i < count; i++) {
        int len = strlen(words[i]);
        normalized[i] = new char[len + 1];
        strcpy(normalized[i], words[i]);
        sortChars(normalized[i]);
    }

    // Търсене на максимален брой еднакви сортирани думи (т.е. анаграми)
    int maxGroup = 0;
    for (int i = 0; i < count; i++) {
        int groupSize = 1;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(normalized[i], normalized[j]) == 0) {
                groupSize++;
            }
        }
        if (groupSize > maxGroup) maxGroup = groupSize;
    }

    // Освобождаване на динамична памет
    for (int i = 0; i < count; i++) {
        delete[] words[i];
        delete[] normalized[i];
    }

    delete[] words;
    delete[] normalized;

    return maxGroup;
}

int main() {
    const int MAX = 500;
    char* input = new char[MAX];

    cout << "Въведи думи: ";
    cin.getline(input, MAX);

    int result = maxAnagramGroup(input);
    cout << "Максимална група анаграми: " << result << endl;

    delete[] input;
    return 0;
}