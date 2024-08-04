#include <iostream>
#include <cstring>
using namespace std;

class Class {

    public:
        Class(const char* s = nullptr, int n = 0);
        Class(const Class&);
        Class& operator=(const Class&);
        ~Class();
        void display() const;
    
    private:
        int number;
        char* str;

        void copy(const Class&);
        void del();
};

Class::Class(const char* s, int n) {
    number = n;

    if (s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else {
        str = nullptr;
    }
}

Class::Class(const Class& other) {
    copy(other);
}

Class& Class::operator=(const Class& other) {
    if (this != &other) {
        del();
        copy(other);
    }
    
    return *this;
}

Class::~Class() {
    del();
}

void Class::copy(const Class& c) {
    number = c.number;

    if (c.str) {
        str = new char[strlen(c.str) + 1];
        strcpy(str, c.str);
    }
    else {
        str = nullptr;
    }
}

void Class::del() {
    delete[] str;
    str = nullptr;
}

void Class::display() const {
    cout << "Name: " << (str ? str : "null") << ", Number: " << number << endl;
}

int main() {

    // Default constructor
    Class c;
    c.display();

    //Parametrized constructor
    Class c1("Example", 42);
    c1.display();

    // Copy constructor
    Class c2 = c1;
    c2.display();

    // Copy assigment operator
    c = c1;
    c1.display();

    return 0;
}