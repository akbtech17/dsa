// nthTriangleRecursion.cpp
#include <iostream>
using namespace std;

int nthTriange(int n) {
	//base case
	if (n == 1) return 1;
	//recursive case
	return n + nthTriange(n - 1);
}

int main() {
	int n;
	cin >> n;
	cout << nthTriange(n);
	return 0;
}