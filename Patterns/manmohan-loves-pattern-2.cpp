// manmohan - loves - pattern - 2.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cout << 1 << endl;;
			continue;
		}
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 or j == i) cout << i;
			else cout << 0;
		}
		cout << endl;

	}
	return 0;
}