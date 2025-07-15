#include <iostream>
using std::cout;

class Test {
    public:
        // Static variables belong to a class
        // No matter how many objects we declare, count is allocated only once and is shared between objects
        static int count = 0;

        Test() {
            a = 10;
            b = 10;
            count++;
        }

        // Static member functions can access only static data members of a class
        static int getCount() {
            a++; // Not allowed
            return count;
        }
    private:
        int a;
        int b;
};

// When we declare static members inside a class, we should declare them outside the class as well
int Test::count = 0; // Global variable but only accessible by Test

class Outer {
    public:
        int a = 10;
        static int b;

        void f() {
            // The outer class can access members of the inner class only if they are public
            i.show();
            cout << i; // no operator<< defined for Inner
        }

        // Visible only inside Outer class
        class Inner {
            public:
                int x = 5;
                void show() {
                    // The inner class can access only static members of the outer class
                    cout << a; // Not allowed
                    cout << b; // Allowed
                }
        };

        Inner i;
};

int Outer::b = 20;

int main() {

    Test t; // a = 10, b = 10, count = 1
    Test t2; // a = 10, b = 10, count = 2

    // Static variable access
    cout << t.count;
    cout << t2.count;
    cout << Test::count;

    cout << Test::getCount();

    return 0;
}