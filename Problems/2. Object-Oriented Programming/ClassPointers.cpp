#include <iostream>

class Base {
    public:
        void f1() {};
        void f2() {};
        void f3() {};
};

class Derived : public Base {
    public:
        void f4() {};
        void f5() {};
};

int main() {

    // Base class pointer and derived class object attached to it
    Base *p = new Derived();
    p->f1();
    p->f2();
    p->f3();
    p->f4(); // No, the pointer is referencing the Base class
    p->f5(); // No, the pointer is referencing the Base class

    Derived *p = new Base(); // Not possible

    return 0;
}