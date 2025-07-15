#include <iostream>
using std::cout;
using std::endl;
 
class Base {
    public:
        Base() {
            cout << "Default of Base" << endl;
        }
 
        Base(int x) {
            cout << "Param of Base" << x << endl;
        }
};
 
class Derived : public Base {
    public:
        Derived() {
            cout << "Default of Derived" << endl;
        }
 
        Derived(int y) {
            cout << "Param of Derived" << y << endl;
        }
 
        Derived(int x, int y) : Base(x) {
            cout << "Param of Derived" << y;
        }
};
 
int main() {
 
    // Default of Base
    // Default of Derived
    Derived d;
 
    // Default of Base
    // Param of Derived
    Derived d(10);
 
    // Param of Base 20
    // Param of Derived 10
    Derived d(20, 10);
 
    return 0;
}