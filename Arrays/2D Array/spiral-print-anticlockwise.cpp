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
		for (int r = sr; r <= er; ++r) cout << arr[r][sc] << ", ";
		sc++;
		if (sr > er or sc > ec) break;

		//print bottom row
		for (int c = sc; c <= ec; ++c) cout << arr[er][c] << ", ";
		er--;
		if (sr > er or sc > ec) break;

		//print right col
		for (int r = er; r >= sr; --r) cout << arr[r][ec] << ", ";
		ec--;
		if (sr > er or sc > ec) break;



		//print top row
		for (int c = ec; c >= sc; --c) cout << arr[sr][c] << ", ";
		sr++;
		if (sr > er or sc > ec) break;



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