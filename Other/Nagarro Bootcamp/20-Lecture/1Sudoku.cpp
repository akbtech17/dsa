// 1mat.cpp
// https://hack.codingblocks.com/app/practice/1/754/problem

#include <iostream>
#include <cmath>
using namespace std;

bool isSafeToPut(int mat[][9], int n, int i, int j, int number) {
	//horizontal and vertical check
	for (int k = 0; k < n; ++k) {
		if (mat[i][k] == number or mat[k][j] == number) return false;
	}

	//checking for submatrix
	int rn = sqrt(n);
	int si = (i / rn) * rn;
	int sj = (j / rn) * rn;

	for (int row = si; row < rn + si; ++row) {
		for (int col = sj; col < rn + sj; ++col) {
			if (mat[row][col] == number) return false;
		}
	}
	return true;
}

bool solveSoduko(int mat[][9], int n, int i = 0, int j = 0) {
	//base case - agar row == 9 hogya mtlb sab rows solve hogyi hai
	if (i == n) {
		//print sudoku
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	//agar col exceed hogye hai toh, next row pe chale jao
	if (j == n) return solveSoduko(mat, n, i + 1, 0);
	//agar cell already filled hai toh next cell ko solve kro
	if (mat[i][j] != 0) return solveSoduko(mat, n, i, j + 1);

	//recursive case
	//lets consider we are working for the empty cell and not for the filled cell
	for (int number = 1; number <= 9; ++number) {
		if (isSafeToPut(mat, n, i, j, number)) {
			//assume num is currently its correct place
			mat[i][j] = number;
			bool kyaBakiRakhPareHai = solveSoduko(mat, n, i, j + 1);
			if (kyaBakiRakhPareHai == true) return true;
		}
	}
	//backtrack here - agar ek bhi number nhi rkh pay toh mtlb pichla number galat tha
	mat[i][j] = 0; //reset krdo matrix ki curr location ko
	return false;
}

int main() {
	int n;
	cin >> n;
	int mat[9][9] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	solveSoduko(mat, n);
	return 0;
}