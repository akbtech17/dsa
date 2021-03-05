// diagonal - traversal.cpp
#include <iostream>
#define MX 100
using namespace std;

int main() {
	int row, col;
	int arr[MX][MX];
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arr[i][j];

	for (int j = 0; j < col; ++j)
	{
		int r = 0;
		int c = j;
		// cout << arr[i][j];

		while (c >= 0 and r < row)
			cout << arr[r++][c--] << " ";

	}

	for (int i = 1; i < row; ++i)
	{
		int r = i;
		int c = col - 1;
		// cout << arr[i][j];

		while (c >= 0 and r < row)
			cout << arr[r++][c--] << " ";

	}
	return 0;
}