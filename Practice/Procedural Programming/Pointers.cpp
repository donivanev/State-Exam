#include <iostream>
using namespace std;

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

	int* p = nullptr;
	int a = 5;

	p = &a;
	cout << "p = " << p << " p* = " << *p << " a = " << a << " &a = " << &a;

    return 0;
}