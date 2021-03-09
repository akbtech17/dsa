// fibonacci - pattern.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0;
	int b = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 and j == 0) {
				cout << 0 << " ";
			}
			else if (i == 1 and j == 0) {
				cout << 1 << " ";
			}
			else {
				int c = a + b;
				cout << c << " ";
				a = b;
				b = c;
			}
		}
		cout << endl;

	}
	return 0;
}