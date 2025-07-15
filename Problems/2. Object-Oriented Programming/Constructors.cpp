#include <iostream>

// Constructors: Default (compiler provided), Non-parameterized, Parameterized, Copy
// Constructors can be overloaded

class A {
    private:
        int a, b;
 
    public:
        // Non-parameterized constructor
        A() {
            a = 0;
            b = 0;
        }
 
        // Parameterized constructor
        A(int valueA, int valueB) {
            setA(valueA);
            setB(valueB);
        }

        // We can combine non-parametrized and parametrized constructors in one
        A(int valueA = 0, int valueB = 0) {
            setA(valueA);
            setB(valueB);
        }

        // Copy constructor
        A(const A &other) {
            a = other.a;
            b = other.b;
 
            // be careful when assigning a pointer
            // p = other.p; - wrong, points to the same memory
            // p = new int[a]; - correct, points to a different memory
        }
 
        void setA(int value) {
            a = value;
        }
 
        void setB(int value) {
            b = value;
        }
};

int main() {
 
    // Both will call the non parameterized constructor
    A obj;
    A obj();

    // Parameterized constructor
    A obj2(5, 10);

    // Copy constructor
    A otherObj(obj2);

    return 0;
}