// pattern - rhombus.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = n * 2 - 1;
	for (int row = 1; row <= n; ++row) {
		if (row <= (n / 2) + 1) {
			//space
			for (int space = 0; space < n / 2 + 1 - row; ++space)
				cout << "\t";
			//stars
			int number = row;
			for (int nums = 1; nums <= 2 * row - 1	; ++nums) {
				if (nums <= row) {

					cout << number << "\t";
					if (nums != row) number++;
				}
				else {
					if (nums == row + 1) number--;
					cout << number-- << "\t";
				}
			}

		}
		else {
			//space
			for (int space = 0; space < row - (n / 2 + 1); ++space)
				cout << "\t";
			//stars
			int number = n - row + 1;
			for (int nums = 1; nums <= 2 * (n - row + 1) - 1	; ++nums) {
				if (nums <= n - row) {

					cout << number << "\t";
					if (nums != n - row + 1) number++ ;
				}
				else {
					cout << number-- << "\t";
				}
			}
		}
		cout << endl;
	}

	return 0;
}