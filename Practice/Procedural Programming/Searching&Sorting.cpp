#include <iostream>
using namespace std;

// O(n)
int linearSearch(int arr[], int n, int x)
{
    for(int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

// O(logn)
int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;
 
        if (arr[mid] == x) {
            return mid;
        }
        
        arr[mid] < x ? left = mid + 1 : right = mid;
    }
    
    return -1;
}

// O(n^2)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }       
        }
    }
}

// O(n^2)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// O(n^2)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int j = i, key = arr[i];

        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }

        arr[j] = key;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[5] = {4, 2, 1, 3, 5};

    //selectionSort(arr, 5);
    //bubbleSort(arr, 5);
    //insertionSort(arr, 5);
    
    print(arr, 5);

    cout << linearSearch(arr, 5, 1);

    selectionSort(arr, 5);
    cout << binarySearch(arr, 5, 1);

    return 0;
}