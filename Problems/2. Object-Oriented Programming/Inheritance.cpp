#include <iostream>
using std::cout;
 
template <typename T>
class Base {
    public:
        void show() {
            cout << x;
        }
    private:
        T x;
};
 
template <typename T>
class Derived : public Base<T> {
    public:
        void display() {
            cout << x << " " << y;
        }
    private:
        T y;
};
 
class Rectangle {
    public:
        Rectangle(int a = 0, int b = 0);
        int getA();
        int getB();
        void setA(int valueA);
        void setB(int valueB);
        int area();
    private:
        int a;
        int b;
};
 
class Cuboid : public Rectangle {
    public:
        Cuboid(int a = 0, int b = 0, int valueC = 0) {
            c = valueC;
            setA(a); // can't access the private members directly
            setB(b); // can't access the private members directly
        }
 
        int getC();
        void setC();
 
        int volume() {
            return getA() * getB() * c;
        }
    private:
        int c;
};

int main() {
 
    Base<int> b;
    // b.x = 25;
    b.show();
 
    Derived<int> d;
    // d.x = 10;
    // d.y = 15;
    d.show();
    d.display();
 
    Cuboid c(10, 5, 3);
    cout << c.getA();
    cout << c.area();
    cout << c.volume();
 
    // isA vs hasA
    // Concept in OOP which defines the ways of which a class can be used
 
    // class Rectangle
    // class Cuboid : public Rectanle - isA
    // class Table { - hasA
    //  Rectangle top;
    //}
 
    return 0;
}