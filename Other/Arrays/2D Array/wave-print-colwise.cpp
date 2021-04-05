// wave - print.cpp
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
		if (j % 2 == 0) {for (int i = 0; i < row; ++i) cout << arr[i][j] << ", ";}
		else {for (int i = row - 1; i >= 0; --i) cout << arr[i][j] << ", ";}
	}
	cout << "END";
	return 0;
}