#include <iostream>
using namespace std;

void binary() {
    int a = 12;  // Binary: 1100 , 0000 1100 (assuming 8-bit for simplicity)
    int b = 7;   // Binary: 0111

    int bitwiseAnd = a & b;
    int bitwiseOr = a | b;
    int bitwiseXor = a ^ b;
    int bitwiseNot = ~a;
    int bitwiseLeftShift = a << 2;
    int bitwiseRightShift = a >> 2;

    cout << bitwiseAnd << endl; // Binary: 0100 (Decimal: 4)
    cout << bitwiseOr << endl; // Binary: 1111 (Decimal: 15)
    cout << bitwiseXor << endl; // Binary: 1011 (Decimal: 11)
    cout << bitwiseNot << endl; // Binary: 1111 0011 (Decimal: -13 in 2's complement)
    cout << bitwiseLeftShift << endl; // Binary: 0011 0000 = 48 in decimal
    cout << bitwiseRightShift << endl; // Binary: 0000 1100 = 3 in decimal
}

void hexadecimal() {
    int hexvalue = 0x1A; // Hexadecimal for 26 in decimal
    int hexvalue2 = 0xFF; // Hexadecimal for 266 in decimal

    cout << hexvalue << endl; // 26
    cout << hexvalue2 << endl; // 255
}

int main() {

    binary();
    hexadecimal();

    return 0;
}