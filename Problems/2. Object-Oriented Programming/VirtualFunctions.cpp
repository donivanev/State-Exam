#include <iostream>
using std::cout;

class Base {
    public:
        virtual void func() {
            cout << "Func of Base";
        }
};

class Derived : public Base {
    public:
        void func() {
            cout << "Func of Derived";
        }
};

int main() {

    Base *p = new Derived();
    p->func(); // if func in the Base class is not virtual -> Func of Base

    p->func(); // but if func is virtual, then -> Func of Derived

    return 0;
}