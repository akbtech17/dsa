// 2nthFibonacci.cpp

#include <iostream>
using namespace std;

int nthFib(int n) {
	if (n == 0 or n == 1) return n;
	return nthFib(n - 1) + nthFib(n - 2);
}

int main() {
	int n = 5;
	for (int i = 0; i < n; i++)
		cout << nthFib(i);
	return 0;
}