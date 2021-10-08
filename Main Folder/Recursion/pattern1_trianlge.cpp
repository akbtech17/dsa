// pattern1_trianlge.cpp
#include <iostream>
using namespace std;

void printTriangle(int n, int i = 0 , int j = 0) {
	if (i == n) return;
	if (j > i) {
		cout << endl;
		printTriangle(n, i + 1, 0);
	}
	else {
		cout << "*\t";
		printTriangle(n, i, j + 1);
	}


	return;
}

int main() {
	int n;
	cin >> n;
	printTriangle(n);
	return 0;
}