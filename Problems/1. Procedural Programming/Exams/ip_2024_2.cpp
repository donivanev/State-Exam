#include <iostream>
using namespace std;

// Под всеки от дадените по-долу фрагменти да се посочи какво ще изведе той на стандартния изход.
// 1)
void print(char* str) {
    char* ptr = str;
    
    while (*ptr != '\0') {
        *ptr = *ptr+1;
        ptr++;
    }
    
    std::cout << str;
}

void main() {
    char str[] = "ACE";
    print(str);
}

// Отговор: 

// 2)
void func(int& x, int* y, int z) {
    int a = 3;
    int b = 5;
    x = z - b;
    *y = 2 * z;
    z = x ? a + *y : 0;
}

void main() {
    int a = 2; int b = 4;
    func(b, &a, b);
    std::cout << a << endl;
    // Отговор: 
    std::cout << b << endl;
    // Отговор: 
}

// 3)
int total = 0;

for (int i = 2; i <= 10; ) {
    if (i % 3 == 0) {
    total = total + i;
}
i += 2;
}
std::cout << total << endl;
// Отговор: 

// 4) При какво условие ще спре да се изпълнява цикълът while?
while ((a || b) && (c || d)) {...}

// а) ако !(a && b) e истина
// б) ако !a || !b || !c || !d e истина
// в) ако (!a && !b) || (!c && !d) e истина
// г) ако (!a || !b) && (!c || !d) e истина
// д) нито един от изброените

// Отговор: 

// 5) Да се попълнят фрагментите така, че функцията reverseMatrixRows да обръща местата на редовете на mat относно центъра
// (т.е. първия ред да се размени с последния и т.н.), а функцията reverseMatrixCols да обръща местата на колоните на матрицата mat относно центъра.
// Нека r и c са съответно брой редове и колони в матрицата.
void reverseMatrixRows(
    int** mat, int r, int c) {
    for (int i = 0; i < _____; ++i)
    for (int j = 0; j < c; ++j)
        swap(mat[i][j], _____________);
}

void reverseMatrixCols(int** mat, int r, int c) {
    for (int i = 0; i < r; ++i)
    for (int j = 0; j < _____; ++j)
        swap(mat[i][j], _____________);
}

// 6) Да се попълнят празните места в рекурсивната функция така, че revStr да обръща елементите на подаден като параметър низ str,
// които се намират на индекси в интервала [start, end];
void revStr(______________ str, unsigned start, unsigned end) {
    if (_________________) {
        return;
    }

    swap(str[start], str[end]);
    revStr(str, ________,__________);
}
