#include <iostream>
using std::cout;
using std::endl;

// By default everything is private
// Data Hiding
// Accessor and Mutators are called Property functions

class A {
    public:
        // Accessor
        int getA(int value) {
            return a;
        }
 
        // Accessor
        int getB(int value) {
            return b;
        }
 
        // Mutator
        void setA(int value) {
            a = value;
        }
 
        // Mutator
        void setB(int value) {
            b = value;
        }
 
        int addition() {
            return a + b;
        }
    private:
        int a, b;
};
 
int main() {
 
    A obj;
 
    // Not permitted
    obj.a = 5;
    obj.b = 10;
    cout << obj.a;
    cout << obj.b;
 
    // Permitted
    obj.setA(5);
    obj.setB(10);
    cout << obj.getA(5) << endl;
    cout << obj.getB(5) << endl;
    cout << obj.addition();
 
    return 0;
}