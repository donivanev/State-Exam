#include <iostream>
using std::cout;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMax(int* arr, int size) {
    int max = *arr;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    return max;
}

void reverseArray(int* arr, int size) {
    int* start = arr, *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

int main() {

    // Pointers are used for accessing heap memory
 
    int *p = nullptr; // declaration, every pointer takes 2 bytes only
    int a = 5;
 
    p = &a; // initialization
    cout << *p; // dereferencing
 
    cout << "p = " << p << " p* = " << *p << " a = " << a << " &a = " << &a;
 
    int a[5] = {2, 4, 6, 8, 10}; // stack
    int *p = new int[5]; // heap
 
    delete[] p; // if we do not delete the dynamic array we can get a memory leak
    p = nullptr;
 
    // Pointer arithmetic
 
    int *q = &a[3];
 
    p++;; p--; p = p + 2; p = p - 2;
    q - p; // if p = 200 and q = 206, the result will be 206 - 200 = 6; 6 / 2 = 3
           // how many elements are these pointers away from each other
 
    *p++; // use the current value, then move to the next position
    *(p++); // move to the next position, then use the value on the new position
 
    int A[] = {2, 4, 6, 8, 10, 12};
    int *p = &A[3]; // p is pointing to 8   
    cout << p[-2]; // 3 - 2 = 1, so a[1] => 4
 
    // Reference
 
    int x = 10;
    int &y = x; // y is alias of x, x and y share the same location in the memory
 
    // References does not consume any memory at all
 
    // We can't make other assignments once it's assigned
    // &y = a; No
 
    int x = 10;
    int *y = &x;
    int* &z = y; // z is a reference to a pointer of type integer

    return 0;
}