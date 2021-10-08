// column - with - maximum - sum.cpp
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
void printColWithMaxSum(int mat[][MX], int row, int col) {
	int mx = INT_MIN;
	int idx = -1;
	for (int c = 0; c < col; ++c)
	{
		for (int r = 1; r < row; ++r)
		{
			mat[0][c] += mat[r][c];
		}
		if (mat[0][c] > mx) {
			mx = mat[0][c];
			idx = c;
		}
	}
	if (idx != -1) cout << "Col " << idx << " have max sum : " << mx;

	return;
}

int main() {
	int mat[MX][MX] = {0};
	int row, col;
	inputMatrix(mat, row, col);
	printMatrix(mat, row, col);
	printColWithMaxSum(mat, row, col);
	return 0;
}