// mazepathD.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countPaths(int row, int col) {
	if (row == 1 and col == 1) {
		return 1;
	}
	else if (row < 1 or col < 1) return 0;
	return countPaths(row - 1, col) + countPaths(row, col - 1) + countPaths(row - 1, col - 1);
}

void printPossiblePaths(int row, int col , int i = 0, int j = 0, string ans = "") {
	if (i == row - 1 and j == col - 1) {
		//print the ans
		cout << ans << " ";
		return ;
	}
	if (i >= row or j >= col) return;
	printPossiblePaths(row, col, i + 1, j, ans + 'V');
	printPossiblePaths(row, col, i, j + 1, ans + 'H');
	printPossiblePaths(row, col, i + 1, j + 1, ans + 'D');
	return;
}

int main() {
	int row, col;
	cin >> row >> col;

	printPossiblePaths(row, col);
	cout << endl << countPaths(row, col);
	return 0;
}