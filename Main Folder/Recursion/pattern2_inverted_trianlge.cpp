// pattern1_trianlge.cpp
#include <iostream>
using namespace std;

void printInvertedTriangle(int n, int i = 0 , int j = 0) {
	if (i == n) return;
	if (j > n - i - 1) {
		cout << endl;
		printInvertedTriangle(n, i + 1, 0);
	}
	else {
		cout << "*\t";
		printInvertedTriangle(n, i, j + 1);
	}


	return;
}

int main() {
	int n;
	cin >> n;
	printInvertedTriangle(n);
	return 0;
}