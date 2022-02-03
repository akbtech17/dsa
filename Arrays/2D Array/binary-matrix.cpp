// binary - matrix.cpp
//https://www.geeksforgeeks.org/a-boolean-matrix-question/?ref=lbp
#include <iostream>
#define MX 100
using namespace std;

void inputMat(int mat[][MX], int &row, int &col) {
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> mat[i][j];
		}
	}
	return;
}
void printMat(int mat[][MX], int row, int col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

//tc - n square
//sc - max of row and col
void updateBinaryMat(int mat[][MX], int row, int col) {
	int ROW[row] = {0};
	int COL[col] = {0};

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (mat[i][j] == 1) {
				ROW[i] = 1;
				COL[j] = 1;
			}
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (ROW[i] == 1 or COL[j] == 1) mat[i][j] = 1;
		}
	}

	return;
}


int main() {
	int row, col;
	int mat[MX][MX] = {0};

	inputMat(mat, row, col);
	updateBinaryMat(mat, row, col);
	printMat(mat, row, col);

	return 0;
}