// 26ElephantChessBoard.cpp
#include <iostream>
using namespace std;

int findNumOfWays(int i, int j) {
	//if it reaches its destination
	if (i == 0 and j == 0) return 1;

	int ans = 0;
	//E can take horizontal steps (row-i-1) steps
	for (int k = 0; k < i; ++k) {
		ans += findNumOfWays(k, j);
	}
	//E can take horizontal steps (col-j-1) steps
	for (int k = 0; k < j; ++k) {
		ans += findNumOfWays(i, k);
	}
	return ans;
}

int main() {
	int row = 3, col = 3;
	cout << findNumOfWays(row, col);
}