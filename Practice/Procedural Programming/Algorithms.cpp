#include <iostream>
using namespace std;

int swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

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

int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int reverseNumber(int num) {
    int reversed = 0;

    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return reversed;
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

int main() {
    
    cout << gcd(3, 8);

    return 0;
}