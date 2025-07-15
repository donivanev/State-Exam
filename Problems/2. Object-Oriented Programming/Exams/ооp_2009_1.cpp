#include <iostream>
using std::cout;

// Попълнете в празните полета текстът, който се отпечатва на конзолата в резултат на изпълнението на съответните програмни конструкции.

class Base {
    public:
        Base() {cout << "Base::Base()\n"; f(); g();}
        Base(Base&) {cout << "Base::Base(Base&)\n"; f(); g();}
        virtual void f() {cout << "Base::f()\n"; g();}
        void g() {cout << "Base::g()\n";}
};

class Derived1 : public Base {
    public:
        Derived1() {cout << "Derived1::Derived1()\n"; f(); g();}
        Derived1(Derived1 &) {cout << "Derived1::Derived1(Derived1&)\n"; f(); g();}
        void f() {cout << "Derived1::f()\n"; g();}
        virtual void g() {cout << "Derived1::g()\n";}
};

class Derived2 : public Derived1 {
    public:
        Derived2() {cout << "Derived2::Derived2()\n"; f(); g();}
        Derived2(Derived2 &) {cout << "Derived2::Derived2(Derived2&)\n"; f(); g();}
        void f() {cout << "Derived2::f()\n"; g();}
        void g() {cout << "Derived2::g()\n";}
};

void fCopy(Base obj) {
    obj.f();
    obj.g();
}

int main() {
    Base *pBase = new Derived2;
    //...

    Derived1 *pDerived1 = new Derived2;
    //...

    Derived2 *pDerived2 = new Derived2;
    //...

    pBase->f();
    //...
    
    pDerived1->f();
    //...

    pDerived2->f();
    //...

    fCopy (*pBase);
    //...
    
    delete pBase, pDerived1, pDerived2;
}