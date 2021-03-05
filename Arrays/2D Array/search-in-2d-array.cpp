// search - in - 2d - array.cpp
#include <iostream>
#define MX 100
using namespace std;

void input2D(int arr[][MX], int &row, int &col) {
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
		}
	}
	return;
}

bool searchIn2D(int arr[][MX], int row, int col, int key) {
	bool isPresent = false;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (arr[i][j] == key) {
				isPresent = true;
				break;
			}
		}
		if (isPresent) break;
	}

	if (isPresent) return true;
	return false;
}

int main() {
	int row, col;
	int arr[MX][MX];
	input2D(arr, row, col);

	int key;
	cin >> key;

	cout << searchIn2D(arr, row, col, key);
	return 0;
}