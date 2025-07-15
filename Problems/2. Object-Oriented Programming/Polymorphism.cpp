#include <iostream>
using std::cout;

// Abstract class - class that can't be instantiated (can't create objects from it, only pointers)
//                - class that contains at leats one pure virtual function
// Interface - abstract class that contains only pure virtual functions
class Device {
    public:
        // We don't need implementation of the base class methods

        virtual void start() = 0; // Pure virtual function
        // { cout << "Device started ..."; }
        virtual void stop() = 0; // Pure virtual function
        // { cout << "Device stopped ..."; }

        // If we have pure virtual functions then the derived classes must override them
        // Otherwise the derived class become abstract

        // The purpose of pure virtual functions is to achieve polymorphism
};

class Phone : public Device {
    public:
        void start() {
            cout << "Phone started ...";
        }
        void stop() {
            cout << "Phone stopped ...";
        }
};

class Laptop : public Device {
    public:
        void start() {
            cout << "Laptop started ...";
        }
        void stop() {
            cout << "Laptop stopped ...";
        }
};

int main() {

    // Runtime polymorphism is achieved when using Base class pointer to Derived class object and
    // calling the overrided method
    
    Device *p = new Phone();
    p->start(); // Phone started ...
    p->stop(); // Phone stopped ...
    // if start and stop functions from the Base class are not virtual -> Device started, Device stopped

    p = new Laptop();
    p->start(); // Laptop started ...
    p->stop(); // Laptop stopped ...

    return 0;
}