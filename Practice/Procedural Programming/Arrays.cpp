#include <iostream>
using namespace std;

// O(n)
int reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

// O(n)
int minMax(int arr[], int n) {
    int min = INT32_MAX; // max

    for (int i = 0; i < n; i++) {
        if (arr[i] > min) { // max
            min = arr[i]; // max
        }
    }

    return min; //max
}

// O(n)
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) 
        return n; 

    int j = 0; 

    for (int i = 0; i < n - 1; i++) 
        if (arr[i] != arr[i + 1]) 
            arr[j++] = arr[i]; 
  
    arr[j++] = arr[n - 1]; 
  
    return j;
}

int main() {

    // static array
    int arr[5] = {4, 2, 1, 3, 5};

    // dynamic array
    int size = 5;
    int* arr = new int[size];
    delete[] arr;

    return 0;
}