// 5 - CountPathsPossibleWithKCoinsInGrid.cpp
#include <iostream>
using namespace std;

int countPathsWithKCoins(int mat[][100], int m, int n, int k, int sum_of_coins = 0) {
	//base case - if boundaries exceed
	if (m < 0 or n < 0) return 0;
	//if dest reached
	if (m == 0 and n == 0) {
		sum_of_coins += mat[m][n];
		// if (sum_of_coins == k) return 1;
		// return 0;
		return sum_of_coins == k ? 1 : 0;
	}
	//there are two poss, from each cell
	// cout << mat[m][n];
	sum_of_coins += mat[m][n];
	//either move down
	int pos1 = countPathsWithKCoins(mat, m - 1, n, sum_of_coins);
	//or move right
	int pos2 = countPathsWithKCoins(mat, m, n - 1, sum_of_coins);
	return pos1 + pos2;
}

// 3 3
// 1 2 3 4 6 5 3 2 1
// 12

int main() {
	int mat[100][100];
	int m, n;
	int k;
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}

	cin >> k;

	cout << countPathsWithKCoins(mat, m - 1, n - 1, k);
	return 0;
}