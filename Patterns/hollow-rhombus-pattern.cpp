// hollow - rhombus - pattern.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int row = 1; row <= n; ++row) {
		//spaces
		for (int spaces = 0; spaces < n - row; ++spaces)
			cout << " ";
		if (row == 1 or row == n) {
			for (int j = 1; j <= n; ++j) cout << "*";
		}
		else {
			for (int j = 1; j <= n; ++j) {
				if (j == 1 or j == n)
					cout << "*";
				else cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
