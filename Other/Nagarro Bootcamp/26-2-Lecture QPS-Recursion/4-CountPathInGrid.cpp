// 4 - CountPathInGrid.cpp
#include <iostream>
using namespace std;

int coutnPathsBRtoTL(int m, int n) {
	//base case - if boundaries exceed
	if (m < 1 or n < 1) return 0;
	//if dest reached
	if (m == 1 and n == 1) return 1;
	//there are two poss, from each cell
	//either move down
	int pos1 = coutnPathsBRtoTL(m - 1, n);
	//or move right
	int pos2 = coutnPathsBRtoTL(m, n - 1);
	return pos1 + pos2;
}

int coutnPathsTLtoBR(int m, int n, int i = 0, int j = 0) {
	//base case - if boundaries exceed
	if (i >= m or j >= n) return 0;
	//if dest reached
	if (i == m - 1 and j == n - 1) return 1;
	//there are two poss, from each cell
	//either move down
	int pos1 = coutnPathsTLtoBR(m, n, i + 1, j);
	//or move right
	int pos2 = coutnPathsTLtoBR(m, n, i, j + 1);
	return pos1 + pos2;
}

int main() {
	cout << coutnPathsTLtoBR(3, 3);
	return 0;
}