// matrix - multiplication.cpp
#include <iostream>
#define MX 100
using namespace std;

int main() {
	int a[][3] = {
		{1, 2, 4},
		{3, 2, 1},
		{3, 1, 4}
	};
	int b[][3] = {
		{2, 1, 2},
		{1, 2, 4},
		{1, 5, 2}
	};

	int m, n, l, k;
	m = n = k = l = 3;

	int res[10][10] = {0};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			//n == l
			//for every i,j
			//we have to multiply row i of m1 with
			//col j of m2
			for (int x = 0; x < n; ++x) {
				res[i][j] += (a[i][x] * b[x][j]);
			}
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}