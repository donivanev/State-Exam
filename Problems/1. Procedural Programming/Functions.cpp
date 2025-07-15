#include <iostream>
using std::cout;
using std::endl;

void passByValue(int a) {
    cout << a << " " << &a << endl;
}

void passByReference(int& a) {
    cout << a << " " << &a << endl;
}

void passByAddress(int *a) {
    cout << a << " " << &a << endl;
}

void overloading(double d) {
    cout << d << endl;
}

void overloading(const char* s) {
    cout << s << endl;
}

void passFunction(void (*func)()) {
    func();
}

// Compiler replaces the function call with the actual code of the function to avoid pushing
// arguments onto the stack, jumping to the function code and returning
inline int square(int x) {
    return x * x;
}

// Function template
template <typename T>
T maxT(T a, T b) {
    return (a > b) ? a : b;
}

void print() {
    cout << "..." << endl;
}

int main() {

    int a = 5;
    cout << a << " " << &a << endl;

    passByValue(a);
    passByReference(a);

    overloading(10.5);
    overloading("Hi!");

    void (*funcPtr)() = print;
    passFunction(funcPtr);

    // Inline functions are functions where the compiler replaces the function call with the actual code
    // of the function to avoid pushing arguments onto the stack, jumping to the function code and returning
    cout << square(5) << endl;

    cout << maxT(5, 6);

    // Lambda function
    auto add = [](int a, int b) { return a + b; };

    return 0;
}