#include <iostream>
using std::cout;

class Parent {
    public:
        void display() {
            cout << "Display of parent";
        }
};

class Child : public Parent {
    public:
        void display() { // overriding
            cout << "Display of child";
        }
};

int main() {

    Parent p;
    p.display(); // Display of parent

    Child c;
    c.display(); // Display of parent
    // If we do not have a display method in Child class it will use the dispay method of Parent class

    return 0;
}