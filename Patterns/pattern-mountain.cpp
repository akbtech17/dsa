// pattern - mountain.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int row = 1; row <= n; ++row) {
		//number
		for (int j = 1; j <= row; ++j) {
			cout << j << "\t";
		}
		//space
		for (int spaces = 1; spaces <= (n * 2) - 1 - (2 * row); ++spaces)
			cout << "\t";
		//number
		for (int j = row; j >= 1; --j) {
			if (row == n and j == row) continue;
			cout << j << "\t";
		}
		cout << endl;
	}
	return 0;
}