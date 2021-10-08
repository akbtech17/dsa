// ganeshas - pattern.cpp
#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	for (int row = 1; row <= n; ++row)	{
		if (row <= (n + 1) / 2) {
			for (int j = 1; j <= n; ++j)	{
				if (row == ((n + 1) / 2)) cout << "*";
				else if (j <= (n + 1) / 2) {
					if (j == 1 or j == (n + 1) / 2) cout << "*";
					else cout << " ";
				}
				else {
					if (row == 1) cout << "*";
				}
			}
		}
		else {
			for (int j = 1; j <= n; ++j)	{
				if (j <= (n + 1) / 2) {
					if (j == (n + 1) / 2 or row == n) cout << "*";
					else cout << " ";
				}
				else {
					if (j == n) cout << "*";
					else cout << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}