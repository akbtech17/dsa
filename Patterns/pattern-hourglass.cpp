// pattern - hourglass.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int total = n * 2 + 1;
	for (int i = 1; i <= total; ++i) {
		if (i <= n + 1) {
			//spaces
			for (int spaces = 1; spaces <= i - 1; ++spaces) {
				cout << "  ";
			}
			//nums
			int num = n - i + 1;
			for (int nums = 1; nums <= total - (2 * (i - 1)); ++nums) {

				if (nums + (i - 1) < n + 1) {
					//print dec numbers
					cout << num-- << " ";
				}
				else if (nums + (i - 1) == n + 1) {
					cout << 0 << " ";
					num = 1;
				}
				else {
					// print inc numbers
					cout << num++ << " ";
				}
			}
		}
		else {
			//spaces
			for (int spaces = 1; spaces <= total - i ; ++spaces) {
				cout << "  ";
			}
			//nums
			int num = i - n - 1;
			for (int nums = 1; nums <= total - (2 * (total - i)); ++nums) {
				if (nums + (total - i ) < n + 1) {
					//print dec numbers
					cout << num-- << " ";
				}
				else if (nums + (total - i ) == n + 1) {
					cout << 0 << " ";
					num = 1;
				}
				else {
					// print inc numbers
					cout << num++ << " ";
				}
			}
		}
		cout << endl;
	}
}