#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		if (i <= (n / 2) + 1) {
			//space
			for (int space = 1; space <= (n / 2) - i + 1; ++space)
				cout << "\t";
			//star
			for (int star = 1; star <= (2 * i) - 1; ++star)
				cout << "*\t";
		}
		else {
			//space
			for (int space = 1; space <= i - (n / 2) - 1; ++space)
				cout << "\t";
			//star
			for (int star = 1; star <= (2 * (n - i + 1)) - 1; ++star)
				cout << "*\t";
		}
		cout << endl;
	}

	return 0;
}