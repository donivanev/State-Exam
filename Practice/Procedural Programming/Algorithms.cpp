#include <iostream>
using namespace std;

int toKbasedSystem(int n, int k) {
    int s = 0, power = 0;

    while (n != 0) {
        int remainder = n % k; //2, 8, 16, ...
        n /= k;
        s += remainder * pow(10, power);
        power++;
    }

    return s;
}

int swap(int* a, int* b) {
    int helper = *a;
    *a = *b;
    *b = helper;
}

int gcd(int a, int b) {
    while (a != b) {
        (a > b) ? a = a - b : b = b - a; 
    }
 
    return a;
}

bool isPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
            return false;
        }
	}

	return true;
}

int minMax(int arr[], int n) {
    int min = INT32_MAX; // max

    for (int i = 0; i < n; i++) {
        if (arr[i] > min) { // max
            min = arr[i]; // max
        }
    }

    return min; //max
}

int main() {
    
    cout << gcd(3, 8);

    return 0;
}
