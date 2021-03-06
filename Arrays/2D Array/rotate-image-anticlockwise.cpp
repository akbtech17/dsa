// rotate - image - anticlockwise.cpp
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
void rotateAntiClockwise(int arr[][MX], int side) {
	//take transpose wrt to left diagonal
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j <= i; ++j) {
			swap(arr[i][j], arr[j][i]);
		}
	}
	// reverse the cols
	for (int col = 0; col < side; ++col) {
		int sr = 0;
		int er = side - 1;
		while (sr <= er) swap(arr[sr++][col], arr[er--][col]);
	}

	printMatrix(arr, side);
	return;
}

int main() {
	int side;
	int arr[MX][MX];
	input2D(arr, side);
	rotateAntiClockwise(arr, side);
	return 0;
}