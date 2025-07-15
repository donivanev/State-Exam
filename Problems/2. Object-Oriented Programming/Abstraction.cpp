#include <iostream>
using std::cout; using std::endl;

// Abstraction - the process of hiding complex implementation details and showing only the essential features of an object

class A {
    public:
        void execute() {
            logic();
        }
    private:
        void logic() {
            cout << "Internal operations" << endl;
        }
};

int main() {

    A a;
    a.execute();

    return 0;
}