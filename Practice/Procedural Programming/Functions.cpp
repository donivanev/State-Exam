#include <iostream>
using namespace std;

int callByValue(int a) {
    cout << a << " " << &a << endl;
}

int callByReference(int& a) {
    cout << a << " " << &a << endl;
}

void overloading(double d) {
    cout << d << endl;
}

void overloading(const char* s) {
    cout << s << endl;
}

void print() {
    cout << "..." << endl;
}

void executeFunction(void (*func)()) {
    func();
}

inline int square(int x) {
    return x * x;
}

template <typename T>
T maxT(T a, T b) {
    return (a > b) ? a : b;
}

int main() {

    int a = 5;
    cout << a << " " << &a << endl;

    callByValue(a);
    callByReference(a);

    overloading(10.5);
    overloading("Hi!");

    void (*funcPtr)() = print;
    executeFunction(funcPtr);

    // Inline functions are functions where the compiler replaces the function call with the actual code
    // of the function to avoid pushing arguments onto the stack, jumping to the function code and returning
    cout << square(5) << endl;

    cout << maxT(5, 6);

    // Lambda function
    auto add = [](int a, int b) { return a + b; };

    return 0;
}