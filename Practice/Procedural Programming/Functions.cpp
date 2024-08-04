#include <iostream>
using namespace std;

int callByValue(int a) {
    cout << a << " " << &a << endl;
}

int callByReference(int& a) {
    cout << a << " " << &a << endl;
}

int main() {

    int a = 5;
    cout << a << " " << &a << endl;

    callByValue(a);
    callByReference(a);

    return 0;
}