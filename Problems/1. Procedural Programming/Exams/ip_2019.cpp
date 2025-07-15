#include <iostream>
using namespace std;

// Даден е двумерен масив с размер 6 на 6 от символи — малки и главни латински букви и цифри. Две клетки в него ще наричаме
// "съседни", ако имат обща стена (т.е. всяка клетка е съседна с най-много четири други, намиращи се под, над, вляво и вдясно
// от нея). Път с дължина N ще наричаме редица a₀, a₁, … aₙ – 1 от клетки, за която:
// 1. за всяко 0 ≤ i < N – 1 е изпълнено, че aᵢ и aᵢ₊₁ са съседни;
// 2. никоя от клетките не се среща повече от веднъж (т.е. няма цикли).
// Да се попълнят празните места в кода на дадените по-долу функция contains и помощната ѝ функция walk. Функцията contains
// получава два аргумента – масив arr от дадения тип char[6][6] и символен низ str. Тя трябва да връща истина тогава и само тогава,
// когато в arr съществува път, чиито клетки образуват точно съдържанието на низа str (вижте примера по-долу). За определеност
// считаме, че функцията трябва да връща истина за празния низ.

// Пример: За дадения по-долу двумерен масив contains трябва да върне истина, ако ѝ бъдат подадени низовете "abcdefgh",
// "A123B123C" или "". За улеснение, за да може да ги видите по-лесно, те са маркирани в сиво.

bool contains(char arr[6][6], const char* str) {
    for (int row = 0; row < /*_____*/; /*_____________*/) // 6; ++row
        for (int col = 0; col < /*_____*/; /*_____________*/) // 6; ++col
            if (walk(arr, row, col, str))
                return /*_________*/; // true
    return /*_________*/; // false
}

bool walk(char arr[6][6], int row, int col, const char* str) {
    if (*str == '\0')
        return /*____________*/; // true

    if (row < 0 || col < 0 || row >= 6 || col >= 6)
        return /*____________*/; // false

    if (arr[row][col] != *str)
        return /*____________*/; // false

    arr[row][col] *= -1;

    bool result =
        walk(arr, row + /*___*/, col, str + 1) ||           // 1
        walk(arr, /*_________*/, /*_________*/, str + 1) || // row - 1, col
        walk(arr, /*_________*/, /*_________*/, str + 1) || // row, col + 1
        walk(arr, /*_________*/, /*_________*/, str + 1);   // row, col - 1
    
    arr[row][col] /*_________________*/; // *= -1; възстановяваме стойността на клетката
    
    return result;
}

//_______________________________________________________

// А) find използва алгоритъма за двоично търсене (binary search), за да провери дали value се съдържа в масива arr,
// състоящ се от size елемента. Функцията връща true ако това е така и false в противен случай.
bool find(int value, int* arr, size_t size) {
    if (size == 0) return /*____________*/; // false
    size_t mid = size / 2;

    if (value == arr[mid]) return /*____________*/; // true
    
    if (value < arr[mid])
        return find(/*____________*/, /*____________*/, /*____________*/); // value, arr, mid
    else
        return find(/*____________*/, arr + /*____________*/, /*____________*/); // value, arr + mid + 1, size - mid - 1
}

// Б) fold_left изпълнява ляво свиване (left fold) върху масива arr, съдържащ size елемента, прилагайки операцията op.
// Началната стойност е nil. Функцията връща стойността op(...op(op(nil, a[0]), a[1]), ..., a[size-1]).
template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil) {
    /*____________*/ result = /*____________*/; // ReturnType, nil

    for (size_t i = 0; i < /*____________*/; ++i) // size
        result = op(/*____________*/,/*____________*/); // result, arr[i]
        
    return result;
}

int op(char Digit, int Result) {
    return (/*____________*/ * 10) + (/*____________*/ - '0'); // Result, Digit
}

// Преобразува символен низ от десетични цифри до величина от тип int
int str_to_int(const char * str) {
    return (str == nullptr) ? 0 : fold_left(str, /*____________*/, op, /*____________*/); // strlen(str), 0
}