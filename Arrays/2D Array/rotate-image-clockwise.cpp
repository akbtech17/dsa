// rotate - image - clockwise.cpp
#include <iostream>
#define MX 100
using namespace std;

void input2D(int arr[][MX], int &side) {
	cin >> side ;
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			cin >> arr[i][j];
		}
	}
	return;
}

void printMatrix(int arr[][MX], int side) {
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//tc - n square
//sc - 1
void rotateClockwise(int arr[][MX], int side) {
	//take transpose wrt to left diagonal
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j <= i; ++j) {
			swap(arr[i][j], arr[j][i]);
		}
	}
	//reverse the rows
	for (int row = 0; row < side; ++row) {
		int sc = 0;
		int ec = side - 1;
		while (sc <= ec) swap(arr[row][sc++], arr[row][ec--]);
	}

	printMatrix(arr, side);
	return;
}

int main() {
	int side;
	int arr[MX][MX];
	input2D(arr, side);
	rotateClockwise(arr, side);
	return 0;
}