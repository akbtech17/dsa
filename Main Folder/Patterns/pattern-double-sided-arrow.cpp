// pattern - double - sided - arrow.cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		if (i <= (n / 2) + 1) {
			//spaces
			for (int spaces = 1; spaces <= ((n / 2) - i + 1) * 2; ++spaces) {
				cout << "  ";
			}
			int number = i;
			//number dec
			for (int nums = 1; nums <= i; ++nums) {
				cout << number-- << " ";
			}
			number++;
			//spaces
			for (int spaces = 1; spaces <= 2 * (i - 1) - 1; ++spaces)
				cout << "  ";
			//number inc
			for (int nums = 1; nums <= i; ++nums) {
				if (i != 1) cout << number++ << " ";
			}
		}
		else {
			//spaces
			for (int spaces = 1; spaces <= (i - (n / 2) - 1) * 2; ++spaces) {
				cout << "  ";
			}
			int number = n - i + 1;
			//number dec
			for (int nums = 1; nums <= n - i + 1; ++nums) {
				cout << number-- << " ";
			}
			number++;
			//spaces
			for (int spaces = 1; spaces <= 2 * (n - i - 1) + 1; ++spaces)
				cout << "  ";
			//number inc
			for (int nums = 1; nums <= n - i + 1; ++nums) {
				if (i != n) cout << number++ << " ";
			}
		}
		cout << endl;
	}
	return 0;
}