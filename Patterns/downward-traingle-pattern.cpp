// downward - traingle - pattern.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int spaces = 1; spaces <= i - 1; ++spaces)
			cout << " ";
		for (int j = 1; j <= n - i + 1; ++j) {
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}