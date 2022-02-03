// pattern - inverted - hourglass.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int total = 2 * n + 1;

	for (int i = 1; i <= total; ++i) {

		if (i <= n + 1) {
			//decreasig number
			int number = n;
			for (int num = 1; num <= i; ++num)
				cout << number-- << " ";
			//spaces
			number++;
			for (int spaces = 1; spaces <= total - (2 * i); ++spaces)
				cout << "  ";
			//increasing number
			for (int num = 1; num <= i; ++num) {
				if (number == 0) {
					number++;
					continue;
				}
				else {
					cout << number++ << " ";
				}
			}
		}

		else {
			int number = n;
			//decreasig number
			for (int num = 1; num <= total - i + 1; ++num)
				cout << number-- << " ";
			number++;
			//spaces

			for (int spaces = 1; spaces <= 2 * (i - n - 1) - 1; ++spaces)
				cout << "  ";
			//increasing number
			for (int num = 1; num <= total - i + 1; ++num)
				cout << number++ << " ";
		}
		cout << endl;
	}
}