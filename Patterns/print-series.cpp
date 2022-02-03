// print - series.cpp
#include <iostream>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	for (int i = 1; n1 > 0; ++i) {
		int series = 3 * i + 2;
		if (series % n2 != 0) {
			n1--;
			cout << series << endl;
		}
	}

	return 0;
}