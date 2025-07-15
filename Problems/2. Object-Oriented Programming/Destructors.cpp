#include <iostream>
using std::cout;
using std::endl;

class A {
    public:
        int *p;

        A() {
            cout << "Initializing ...";
            p = new int[10];
        }
        // Destructor cannot be overloaded
        ~A() {
            cout<< "Destroying ...";
            delete[] p;
        }
};

// Virtual Destructors
class Base {
    public:
        Base() {
            cout << "Base constructor" << endl;
        }
        virtual ~Base() {
            cout << "Base destructor" << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Derived constructor" << endl;
        }
        ~Derived() {
            cout << "Derived destructor" << endl;
        }
};

int main() {

    A *p = new A(); // Constructor called, allocating resources
    delete p; // Destructor called, deallocating resources

    Base *p = new Derived();

    // If Base class destructor is not virtual
    delete p; // Base destructor

    // If Base class destructor is virtual
    delete p; // Derived destructor
              // Base destructor

    return 0;
}