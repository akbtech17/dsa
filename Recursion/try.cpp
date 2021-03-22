// try.cpp
#include <iostream>
#include<vector>
using namespace std;

int factorialOfNumber(int n) {
	if (n == 0) return 1;
	return n * factorialOfNumber(n - 1);
}

int main() {
	// int n = 5;
	// cout << factorialOfNumber(n);
	vector<int> v({1, 2, 4, 5});
	for (auto el : v) cout << el;
	return 0;
}