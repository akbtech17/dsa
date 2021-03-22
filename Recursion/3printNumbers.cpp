// 3printNumbers.cpp
#include <iostream>
using namespace std;

void printAscendingNumbers(int n) {
	if (n == 0) return ;
	printAscendingNumbers(n - 1);
	cout << n << " ";
	return ;
}
void printDescendingNumbers(int n) {
	if (n == 0) return ;
	cout << n << " ";
	printDescendingNumbers(n - 1);
	return ;
}

int main() {
	int n = 5;
	printAscendingNumbers(n) ;
	cout << endl;
	printDescendingNumbers(n);
	return 0;
}