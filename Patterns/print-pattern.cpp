// print - pattern.cpp
#include <iostream>
using namespace std;

void printPattern(int n) {
	for (int i = 0; i < n; ++i)
	{
		if (i <= (n / 2)) {
			//decreasing spaces

			//increasing stars
			for (int j = 0; j < (2 * i + 1); ++j) cout << "*";
		}
		else {
			//spaces
			//stars
			for (int j = 0; j < (2 * i + 1) - n; ++j) cout << "*";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	printPattern(n);
	return 0;
}