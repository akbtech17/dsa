// diagonal - traversal.cpp
#include <iostream>
#define MX 100
using namespace std;

void printDiagonally(int arr[][MX], int row, int col) {
	int i = 0;
	int j = 0;

	bool isUp = true;

	for (int k = 0; k < row * col;) {
		if (isUp) {
			for (; i >= 0 and j < col; i--, j++) {
				cout << arr[i][j] << " ";
				k++;
			}

			//set i j according to the direction
			if (i < 0 and j <= col - 1) i = 0;
			if (j == col) i = i + 2, j--;
		}
		else {
			for (; j >= 0 and i < row; j--, i++) {
				cout << arr[i][j] << " ";
				k++;
			}

			//set i j according to the direction
			if (j < 0 and i <= row - 1) j = 0;
			if (i == row) j = j + 2, i--;
		}
		isUp = !isUp;
	}

	return;
}

int main() {
	int row, col;
	int arr[MX][MX];
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];
	printDiagonally(arr, row, col);
	return 0;
}