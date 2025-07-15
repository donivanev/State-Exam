#include <iostream>
using namespace std;

// 1) Да се попълнят празните места в кода на функцията removeWhitespace така, че тя да премахва от непразния низ str всички 
// whitespace символи.
bool isWhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

/*________*/ removeWhitespace(char* str) // char*
{
    size_t read = 0, write = 0;
    
    while(str[read]) {
        if (isWhitespace(/*_________________*/)) // str[read]
            read/*_____________________________*/; // ++
        else
            str[write++] = /*__________________*/; // str[read++]
}

str[/*____________________*/] = '\0'; // write

return str;

// 2) Под всеки от фрагментите да се посочи какво ще изведе той на стандартния изход.
for (int i = 0; i < 10; ++i) {
    if (i % 2) continue;
    cout << i;
}

// 02468

int i = 0x10;
cout << i;

// 16

int a=1,b=2,c=3;
cout << (a ? b : c);

// 2

char str[] = "abc";
char* p = str;
++p;
++*p;
cout << str;

// acc

// 3) Да се попълнят празните места в кода на функцията pass така, че функцията bubbleSort да сортира в нарастващ ред елементите
// на масива arr с размер size. Абстрахирайте се от това, че алгоритъмът, разписан по този начин, работи неефикасно.
void pass(int* arr, size_t size, bool& swappedAtLeastOnce)
{
    if (size /*_____*/ 1) // <=
        return;
    
    if (arr[0] /*________________*/) { // > arr[1]
        std::swap(arr[0], arr[1]);
        swappedAtLeastOnce = /*_________*/; // true
    }
    pass(/*__________________________*/, /*__________________________*/, /*__________________________*/);
    // arr + 1, size - 1, swappedAtLeastOnce
}

void bubbleSort(int* arr, size_t size)
{
    bool swappedAtLeastOnce = false;
    pass(arr, size, swappedAtLeastOnce);
    if (swappedAtLeastOnce)
        bubbleSort(arr, size);
}

// 4) Да се посочи какво ще изведе на стандартния изход следният фрагмент.
int x = 2;
int arr[] = {10, 20, 30};
cout << "\nA: " << 5./x;      // A: 2.5
cout << "\nB: " << (x << 4);  // B: 100 000 = 32
cout << "\nC: " << arr[!x];   // C: 10
cout << "\nD: " << *(arr+x);  // D: 30
cout << "\nE: " << (2 + x++); // E: 4