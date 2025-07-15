#include <iostream>
using namespace std;
 
// using std::cout;
// using std::endl;
 
int main() {
 
    2.5f; // float literal

    // Manipulators
    // int - hex, oct, dec
    // float - fixed, scientific
    // other - set, left, right, ws

    cout << hex << 163; // A3
    cout << fixed << 125.731;
    cout << set(10) << "Hello";
 
    // Increment/decrement operators
 
    int x = 5, y = 10, z;
 
    z = x++ * y; // z = 50, y = 10, x = 6
    // or
    z = ++x * y; // z = 60, y = 10, x = 6
 
    // Bitwise - & | ~ ^ << >>
 
    int x = 11, y = 7, or, xor, leftShift, rightShift;
 
    or = x | y; // 00001011 or 00000111 = 00001111 => or = 15
    xor = x ^ y; // equal numbers are 0, same numbers are 1; xor = 00001100 = 12
    ~x; // if x is positive then the result is -(x + 1)
    leftShift = x << 3; // x * 2^3
    rightShift = x >> 3; // x / 2^3
 
    // Short circuit
 
    int a = 5, b = 7, i = 5;
 
    if (a > b && ++i < b) {} // false and 5 < 7
 
    // but if
    a = 15;
 
    if (a > b && ++i < b) {} // true and 6 < 7
 
    // Do not use increment operators in the second part of a logical expression
 
    // Dynamic declaration
    if (int k = 5; k < 5) {}
 
    // Switch case
    switch (int/char) {
        case 1: 1;
        case 2: 2;
        default: 0;
    }
 
    // If we don't put break statements it will execute every case
 
    // Loops
 
    for(;;) == while(true)
 
    for (int i = 0, j = 4; i < j; i++, j--)   
        cout<< "Hello"; // 2 times
 
    // Skipping array size
    for (int x : arr) {
        cout << x;
    }
 
    return 0;
}