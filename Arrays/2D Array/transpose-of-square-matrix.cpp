// transpose - of - matrix.cpp
#include <iostream>
#define side 3
using namespace std;


void findTranspose(int arr[][side]) {
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j <= i; ++j) {
			swap(arr[i][j], arr[j][i]);
		}
	}
	return;
}

void printMatrix(int arr[][side]) {
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int main() {
	// int side = 3;
	int arr[][side] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	findTranspose(arr);
	printMatrix(arr);
	return 0;
}