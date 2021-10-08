// 4WasysToReachDestination.cpp
// https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/

#include <iostream>
using namespace std;

int countWays(int row, int col ) {
	//base case - standing on first cell is one way
	if (row == 1 and col ==  1) return 1;
	//if out of bounds - no way
	if (row < 1 or col < 1) return 0;
	return countWays(row, col - 1) + countWays(row - 1, col);
}

int main() {
	int row = 3;
	int col = 2;
	cout << countWays(row, col);
	return 0;
}