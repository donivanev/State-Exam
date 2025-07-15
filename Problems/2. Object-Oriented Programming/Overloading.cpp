#include <iostream>
using std::cout;
using std::ostream;
 
class Complex {
    public:
        Complex(int r = 0, int i = 0) {
            real = r;
            imaginary = i;
        }
        
        // Overloading as a member function
        Complex operator+(Complex &c) {
            Complex temp;
            temp.real = real + c.real;
            temp.imaginary = imaginary + c.imaginary;
            return temp;
        }
 
        // Overloading as a friend function
        // Friend functions can't be implemented inside a class
        friend ostream& operator<< (ostream &o, Complex &c);
    private:
        int real;
        int imaginary;
};
 
// This function doesn't belong to the class itself but it's marked as a friend (we don't need scope resolution operator)
// operator << CAN'T be overloaded as a member function
ostream& operator<< (ostream &o, Complex &c) {
    o << c.real << "+i" << c.imaginary;
    return o;
}

// Friend classes can access members of objects of other classes
class B;

class A {
    friend B;
    private:
        int a = 10;
};

class B {
    public:
        A obj;
        void f() { cout << obj.a; }
};
 
int main() {
 
    Complex c1(3, 7);
    Complex c2(5, 4);
    Complex c3;
 
    // "+" is overloaded
    c3 = c1 + c2;
 
    // "<<" is overloaded
    cout << c3;
 
    // Scope resolution operator can't be overloaded
 
    return 0;
}