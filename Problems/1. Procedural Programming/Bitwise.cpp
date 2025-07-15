#include <iostream>
using std::cout;
using std::endl;

// Bitwise operators are applied only to int, short, long, char, bool data types

// 1100 = 1 * 2^3 + 1 * 2^2 + 0 * 2^1 + 0 * 2^0 = 8 + 4 + 0 + 0 = 12
// 0x1A = 1 * 16^1 + A * 16^0 = 16 + 10 = 26

void binary() {
    int a = 12;  // Binary: 1100 , 0000 1100 (assuming 8-bit)
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
    cout << bitwiseRightShift << endl; // Binary: 0000 0011 = 3 in decimal
}

void octal() {
    // 0 * 8^2 + 1 * 8^1 + 0 * 8^0 = 8
    int octValue = 010; // Octal for 8 in decimal
    // 0 * 8^2 + 5 * 8^1 + 3 * 8^0 = 40 + 3 = 43
    int octValue2 = 053; // Octal for 43 in decimal

    cout << octValue << endl; // 8
    cout << octValue2 << endl; // 43
}

void hexadecimal() {
    // 1 * 16^1 + A * 16^0 = 16 + 10 = 26
    int hexvalue = 0x1A; // Hexadecimal for 26 in decimal
    // F * 16^1 + F * 16^0 = 17F = 255
    int hexvalue2 = 0xFF; // Hexadecimal for 255 in decimal

    cout << hexvalue << endl; // 26
    cout << hexvalue2 << endl; // 255
}

int main() {

    binary();
    octal();
    hexadecimal();

    return 0;
}