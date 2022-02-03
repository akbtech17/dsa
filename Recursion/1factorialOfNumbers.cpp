// 1factorialOfNumbers.cpp
#include <iostream>
using namespace std;

int factorialOfNumber(int n) {
	if (n == 0) return 1;
	return n * factorialOfNumber(n - 1);
}

int main() {
	int n = 5;
	cout << factorialOfNumber(n);
	return 0;
}