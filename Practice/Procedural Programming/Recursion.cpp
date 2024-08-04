#include <iostream>
using namespace std;

double sum(int n) {
	if (n == 0) return 0;

	double a;
	cin >> a;

	return sum(--n) + a;
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