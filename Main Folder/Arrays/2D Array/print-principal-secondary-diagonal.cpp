// print - principal - secondary - diagonal.cpp
#include <iostream>
#include <climits>
#define MX 100
using namespace std;

void inputMatrix(int mat[][MX], int &row, int &col) {
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> mat[i][j];
	return;
}

void printMatrix(int mat[][MX], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return;
}

//tc - n square
void printDiagonals(int mat[][MX], int row, int col) {
	cout << "\nPrincipal Diagonal : ";
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i == j) cout << mat[i][j] << " ";
		}
	}
	cout << "\nSecondary Diagonal : ";
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i + j == row - 1) cout << mat[i][j] << " ";
		}
	}
	return;
}

//tc = n
void printDiagonals2(int mat[][MX], int row, int col) {
	cout << "\nPrincipal Diagonal : ";
	int j = 0;
	for (int i = 0; i < row; ++i, ++j) {
		cout << mat[i][j] << " ";
	}
	cout << "\nSecondary Diagonal : ";
	j = col - 1;
	for (int i = 0; i < row; ++i, --j) {
		cout << mat[i][j] << " ";
	}
	return;
}

int main() {
	int mat[MX][MX] = {0};
	int row, col;
	inputMatrix(mat, row, col);
	printMatrix(mat, row, col);
	printDiagonals(mat, row, col);
	printDiagonals2(mat, row, col);
	return 0;
}