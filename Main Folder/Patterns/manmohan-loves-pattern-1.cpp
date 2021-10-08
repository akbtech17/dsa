// manmohan - loves - pattern - 1.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
		{
			if (i < 3) cout << 1;
			else if (i % 2 == 0) cout << 1;
			else if (i % 2 != 0) {
				if (j == 0 or j == i) cout << 1;
				else cout << "0";
			}
		}
		cout << endl;

	}
	return 0;
}