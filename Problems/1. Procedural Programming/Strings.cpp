#include <iostream>
using std::cin;
using std::cout;

//preffix, suffix, substring
// number - '0' => converts a character digit ('5') into its corresponding integer value (5)

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int strlen(const char* str) {
    int count = 0;

    while (str[count] != '\0')
        count++;
    
    return count;
}

void strcpy(char* dest, const char* src) {
    int i = 0;

    while(src[i]) {
        dest[i] = src[i];
        ++i;
    }

    dest[i] = '\0';
}

void strcpyPtr(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }

    *dest = '\0';

    //while (*dest++ = *src++) ;
}

unsigned strcmp(const char* str1, const char* str2) {
    int i = 0;

    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] < str2[i]) {
            return -1;
        }
        else if (str1[i] > str2[i]) {
            return 1;
        }
    }
    
    return 0;
}

char* strduplicate(char* copyStr, char* str) {
    strcpy(copyStr, str);
    
    //strcpy_s(copyStr, 50, str); copyStr[strlen(str)] = '\0'; ?? 

    return copyStr;
}

char* reverseString(char* str) {
    int n = strlen(str);

    for (int i = 0; i < n / 2; i++) {
        char c = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = c;
    }

    return str;
}

bool isPalindrome(const char* str) {
    int n = strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }

    return true;
}

void RLE(const char* str) {
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        int count = 1;

        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        cout << str[i] << count;
    }
}

unsigned countWords(char* str) {
    unsigned i = 0, counter = 0;

    while (str[i]) {
        while (!isLetter(str[i])) {
            i++;
        }
        if (str[i]) {
            counter++;
        }
        while (isLetter(str[i])) {
            i++;
        }
    }
    
    return counter;
}

bool isPrefix(const char* str, const char* prefix) {
    int strLength = strlen(str), prefixLength = strlen(prefix);
    
    if (prefixLength > strLength) {
        return false;
    }
    
    for (int i = 0; i < prefixLength; ++i) {
        if (str[i] != prefix[i]) { // for Suffix => str[strLength - suffixLength + i] != suffix[i]
            return false;
        }
    }
    
    return true;
}

int main() {

    // char str[] = "Hello" == char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}
    // char str[6] = "Hello" == char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
 
    char str[50];
    cin >> str; // reads a single word (stops at whitespace like space, tab or newlinw)
    cin.get(str, 50); // reads an entine line but stops at the first newline
    cin.getline(str, 50); // reads an entire line including spaces and removes the trailing newline "\n"

    // Dynamic allocation of a string
    char* copyStr = new char[strlen(str) + 1];
    cout << strduplicate(copyStr, str);
    delete[] copyStr;

    return 0;
}