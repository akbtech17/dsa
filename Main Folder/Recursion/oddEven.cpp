// oddEven.cpp
#include <iostream>
using namespace std;

void printOddEven(int n) {
	//base case
	if (n == 0) return;
	//recursive case
	if (n % 2 != 0) cout << n << endl;
	printOddEven(n - 1);
	if (n % 2 == 0) cout << n << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	printOddEven(n);
	return 0;
}