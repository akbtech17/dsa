// pattern - hourglass.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int total = n * 2 + 1;
	for (int i = 1; i <= total; ++i) {
		for (int j = 0; j <= total; ++j) {
			if (i <= n + 1) {
				if (j <= i - 1) cout << " ";
				else cout << "*";
			}
			else if (i > n + 1) {
				if (j <= n - (i - 1)) cout << " ";
				else cout << "*";
			}
		}
		cout << endl;
	}
}