// pattern - with - zeros.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 or j == i) cout << i + 1 << "\t";
			else cout << 0 << "\t";
		}
		cout << endl;

	}
	return 0;
}