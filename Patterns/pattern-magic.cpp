// pattern - magic.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = (2 * n) - 1;
	for (int i = 1; i <= n; ++i) {
		//one partition
		if (i <= (n / 2) + 1) {
			//print star
			for (int star = 1; star <= (n / 2 + 2 - i); star++) cout << "*";
			//print space
			for (int space = 1; space <= (2 * (i - 1) - 1); ++space) cout << " ";
			//print star
			for (int star = 1; star <= (n / 2 + 2 - i); star++) {
				if (i == 1 and star == 1) continue;
				cout << "*";
			}
		}
		else {
			//print star
			for (int star = 1; star <= i - (n / 2); star++) cout << "*";
			//print space
			for (int space = 1; space <= (2 * (n - i) - 1); ++space) cout << " ";
			//print star
			for (int star = 1; star <= i - (n / 2); star++) {
				if (i == n and star == 1) continue;
				cout << "*";
			}
		}
		cout << endl;
	}

	return 0;
}
