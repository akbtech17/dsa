// staircase - search.cpp
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

//tc - row+col
//sc - 1
bool searchInSorted2d(int arr[][MX], int row, int col, int key) {
	if (key<arr[0][0] or key>arr[row - 1][col - 1])
		return false;
	//start from the top right corner
	int i = 0;
	int j = col - 1;
	bool isPresent = false;
	while (i<row and j >= 0) {
		if (arr[i][j] == key) {
			isPresent = true;
			break;
		}
		else if (arr[i][j] < key) i++;
		else j--;
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

	cout << searchInSorted2d(arr, row, col, key);
	return 0;
}