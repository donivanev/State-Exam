#include <iostream>
using namespace std;

// Под всеки от дадените по-долу фрагменти да се посочи какво ще изведе той на стандартния изход. Упътване: ASCII кодовете на
// символите 'A' и 'a' са съответно 65 и 97.
// 1)
void print(char* p) {
    if (*(p++)) print(++p);
    std::cout << *(--p);
}
void main() {
    char str[] = "012345";
    print(str);
}

// Отговор: 531

// 2)
const size_t size = 3;
int matrix[size][size] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
};
std::cout << matrix[1][2] << *matrix[2];
// Отговор: 67
std::cout << **matrix << *(*(matrix + 2) + 1);
// Отговор: 18

// 3)
char symb = 'A';
switch(symb) {
    case 0 : std::cout << "0";
    case 65 : std::cout << "1";
    case 'a' : std::cout << "2";
    default : std::cout << "d";
}
// Отговор: 12d

// 4)
unsigned x = 8, y = 3;
while (x > 0) {
    if (x % y == 0) break;
    else x -= 1;
}
std::cout << x;
// Отговор: 6

// 5)
unsigned a = 4, b = 8, c = 2;
std::cout << ((a > c) ? (b > a ? b : a) : c);
// Отговор: 8

// 6) Да се попълнят празните места в кода на функцията insert така, че функцията insertSort да сортира в нарастващ ред
// елементите на масива arr с размер size.
void insert(int* arr, int index) {
    int key = arr[index];
    int j = /*____________*/; // index - 1
    while (/*_____________*/ && /*_____________*/) { // j >= 0 && arr[j] > key
        /*_____________*/; // arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
}
void insertSort(int* arr, int size) {
    for(int i = 1; i < size; i++) {
        insert(arr, i);
    }
}

// 7) Да се попълнят празните места във функцията така, че rotateArray да завърта с k стъпки надясно елементите на масива arr
// с размер size. Стандартната функция std::reverse(start, end) обръща реда на елементите на масив, зададен чрез указатели start
// към началото му и end, сочещ след последния му елемент. При nums = {1, -2, 13, 40, 5} и k = 2 резултатът е {40, 5, 1, -2, 13}.
void rotateArray(int* nums, int k, int size) {
    if (size == 0 || k % size == 0)
        return;
    k %= size;
    std::reverse(nums, nums+size);
    std::reverse(/*_____*/, /*________*/); // nums, nums + k
    std::reverse(/*_____*/, /*________*/); // nums + k, nums + size
    // if we change the last two rows we will get wrong result!
}