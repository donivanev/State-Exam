#include <iostream>
using namespace std;

void readArr(unsigned* arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void sortLex(unsigned* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            if (arr[i] - 'a' > arr[i + 1] - 'a') {
                unsigned temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main() {

    int n = 0;

    cin >> n;

    unsigned* arr = new unsigned[n];
    
    // 13,14,7,2018,9,0
    readArr(arr, n);
    sortLex(arr, n);
    // 0,13,14,2018,7,9

    delete[] arr;

    return 0;
}