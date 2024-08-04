#include <iostream>
#include <cstring>
using namespace std;

// Base class
class Person {

    public:
        void readPerson(const char*, const char*);
        void printPerson() const;

    private:
        char* name;
        char* ucn;
};

void Person::readPerson(const char* na, const char* uc) {
    name = new char[strlen(na) + 1];
    strcpy(name, na);

    ucn = new char[strlen(uc) + 1];
    strcpy(ucn, uc);
}

void Person::printPerson() const {
    cout << "Name: " << name << endl;
    cout << "UCN: " << ucn << endl; 
}

// Derived Class
class Student : public Person {
    
    public:
        void readStudent(const char*, const char*, long, double);
        void printStudent() const;
    private:
        long FN;
        double gpa;
};

void Student::readStudent(const char* na, const char* uc, long fn, double g) {
    readPerson(na, uc);
    FN = fn;
    gpa = g;
}

void Student::printStudent() const {
    cout << "Faculty number: " << FN << endl;
    cout << "GPA: " << gpa << endl; 
}

int main() {

    Student s;
    s.readStudent("Ivan Ivanov", "0052175787", 81992, 4.5);
    s.printStudent();

    return 0;
}