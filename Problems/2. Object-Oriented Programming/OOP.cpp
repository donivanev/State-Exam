#include <iostream>
using std::cout;
 
// Struct - by default everything is public
// Class - by default everything is private
 
class Rectangle {
    public:
        int height, width;
 
        // If we write functions inside the class they are automatically inline functions
        // Inline functions - their machine code will be replaced wherever the function is called
        int area() {
            return height * width;
        }

        int perimeter();
};
 
// Scope Resolution Operator
// Non-inline function
int Rectangle::perimeter() {
    return 2 * (height + width);
}
 
int main() {
 
    // OOP principles
 
    // Abstraction - user doesn't know how are the methods implemented, he just uses them
    // Encapsulation - user can access only reasonable data, he can't modify the main logic and data of a class; hide data (private) and show functions (public)
    // Inheritance - acquiring the features of existing class into a new class that is deriving a class from an existing class
    // Polymorphism
 
    // Types of functions in a class
    // Constructors - default, non-parametrized, parametrized, copy
    // Accessors - get
    // Mutators - set
    // Facilitators - actual functions used in a class, the main functionality
    // Inspector functions (enquiry) - isSomething()
    // Destructors
 
    Rectangle r;
    Rectangle *p;
    p = &r;
    r.height = 10; // . is used for accessing the members of an object using variable name
    p->height = 10; // -> is used for accessing the members of an object using a pointer on an object; instead of dereferencing operator
    // p->length == (*p).length;
 
    // Create an object in heap
 
    Rectangle *p = new Rectangle(); // every pointer takes 2 bytes only
    p->height = 15;
    p->width = 10;
    cout << p->area();
 
    return 0;
}