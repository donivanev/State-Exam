#include <iostream>
using std::cout;

int main() {

    const int x = 10; // constant identifier, not a variable, consumes memory
    // x++; not allowed

    int y = 10;

    const int *ptr1 = &y; // pointer to a constant integer (data is locked)
    ++*ptr1; // not allowed, can't modify y
    cout << *ptr1; // allowed, can read y

    int z = 10;

    int const *ptr2 = &y; // pointer to an integer constant (data is locked)
    ++*ptr2; // not allowed, can't modify z
    ptr2 = &z; // allowed, can read z

    int * const ptr3 = &y; // constant pointer of type integer (pointer is locked, data is not locked)
    ptr3 = &z; // not allowed, address can't be modified
    ++*ptr3; // allowed, can modify z

    const int * const ptr4 = &y; // constant pointer to integer constant (pointer is locked, data is locked)
    ptr4 = &z; // not allowed, address can't be modified
    ++*ptr4; // not allowed, can't modify z
}