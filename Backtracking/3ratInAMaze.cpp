// 3ratInAMaze.cpp
#include <iostream>
#define MX 1001
using namespace std;

int cnt = 0;
int sol[MX][MX] = {0};

bool findCheese(char mat[][MX], int row, int col, int i = 0, int j = 0) {
	//base case
	if (i == row - 1 and j == col - 1) {
		sol[i][j] = 1;
		if (cnt == 0) {
			for (int i = 0; i < row; ++i) {
				for (int j = 0; j < col; ++j) {
					cout << sol[i][j] << " ";
				}
				cout << endl;
			}
			cnt++;
		}
		return true;
	}
	if (cnt == 1) return true;
	if (mat[i][j] == 'X') return false;
	if (i >= row or j >= col) return false;
	sol[i][j] = 1;
	bool leftAnsHai = findCheese(mat, row, col, i, j + 1);
	bool neecheAnsHai = findCheese(mat, row, col, i + 1, j);
	if (neecheAnsHai or leftAnsHai) return true;
	//backtrack
	sol[i][j] = 0;
	return false;
}


int main() {
	char mat[MX][MX];
	int row, col;
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> mat[i][j];
		}
	}

	if (!findCheese(mat, row, col)) cout << -1;

	return 0;
}
