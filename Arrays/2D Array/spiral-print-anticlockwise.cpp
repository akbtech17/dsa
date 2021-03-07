// spiral - print - anticlockwise.cpp
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

//tc - n square
//sc - 1
void spiralAntiClockwise(int arr[][MX], int row, int col) {
	int sr, sc, er, ec;
	sr = sc = 0;
	er = row - 1;
	ec = col - 1;

	while (sr <= er and sc <= ec) {

		//print left col
		for (int i = sr; i <= er; ++i) cout << arr[i][sc] << ", ";
		sc++;
		//print bottom row
		for (int j = sc; j <= ec; ++j) cout << arr[er][j] << ", ";
		er--;
		//print right col
		if (sc <= ec) {
			for (int i = er; i >= sr; --i) cout << arr[i][ec] << ", ";
			ec--;
		}

		//print top row
		if (sr <= er) {
			for (int j = ec; j >= sc; --j) cout << arr[sr][j] << ", ";
			sr++;
		}
	}
	cout << "END";
	return;
}

int main() {
	int row, col;
	int arr[MX][MX];
	input2D(arr, row, col);
	spiralAntiClockwise(arr, row, col);
	return 0;
}