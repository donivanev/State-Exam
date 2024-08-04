#include <iostream>
using namespace std;

int reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

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

    int arr[5] = {4, 2, 1, 3, 5};

    return 0;
}