#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

long max(long* pmax, int n) {
	if (n == 0) {
		return *pmax;
	}

	long a;
	cin >> a;

	if (*pmax < a) {
		*pmax = a;
	}

	return max(pmax, --n);
}

int main() {

	int* p = nullptr;
	int a = 5;

	p = &a;
	cout << "p = " << p << " p* = " << *p << " a = " << a << " &a = " << &a;

    return 0;
}