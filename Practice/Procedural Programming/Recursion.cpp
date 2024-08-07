#include <iostream>
using namespace std;

double sum(int arr[], int n) {
	if (n <= 0) return 0;
	return sum(arr, n - 1) + arr[n - 1];
}

int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int reverseNumber(int n, int power) {
    if (n == 0) return 0;
    return n % 10 * pow(10, power) + reverseNumber(n / 10, --power);
}

double reverse(int n) {
	int a;
	cin >> a;

	if (n > 1) {
		reverse(n - 1);
	}

	cout << a << " ";

	return n;
}

bool isPalindrome(int start, int end, const char* str) {
    if (start >= end) return 1;
    if (str[start] != str[end]) return 0;
    return isPalindrome(++start, --end, str);  
}

int main() {


    return 0;
}