#include <iostream>

// Access specifiers: public, protected, private
//                  private  protected  public
// inside class        ok       ok        ok
// inside derived      no       ok        ok
// on object           no       no        ok

class Base {
    private:
        int a;
    protected:
        int b;
    public:
        int c;
    
        void funcBase() {
            a = 10;
            b = 20;
            c = 30;
        }
};

class Derived : Base {
    public:
        void funcDerived() {
            a = 1; // Can't access
            b = 2; // OK
            c = 3; // OK
        }
};

int main() {

    Base x;
    x.a = 15; // Can't access
    x.b = 30; // Can't access
    x.c = 90; // OK

    return 0;
}