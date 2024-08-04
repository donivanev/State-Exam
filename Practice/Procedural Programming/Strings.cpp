#include <iostream>
using namespace std;

//preffix, suffix, substring

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int strLen(char str[]) {
    int count = 0;

    while (str[count] != '\0')
        count++;
    
    return count;
}

void strCpy(char* copy, const char* src) {
    int index = 0;

    while(src[index]) {
        copy[index] = src[index];
        ++index;
    }

    copy[index] = '\0';
}

void strcpyPtr(char* dest, const char* src) {
    while (*dest++ = *src++) ;
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

    char str[50];
    // reads input until encounters whitespace (space, tab or newline) and skips leading whitespace
    // often used to read a single word
    cin >> str;
    cout << reverseString(str);

    char str1[100];
    // reads input until encounters a newline character or a specified delimeter ('\n') and includes leading whitespace
    // often used when reading full lines of text or inputs where spaces are significant
    cin.getline(str1, 50);
    cout << str1;

    // Dynamic allocation of a string
    char* copyStr = new char[strlen(str) + 1];
    cout << strduplicate(copyStr, str);
    delete[] copyStr;

    return 0;
}