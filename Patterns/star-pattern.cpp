// star - pattern.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int spaces = 1; spaces <= n - i; ++spaces)
			cout << "  ";
		for (int star = 1; star <= i; ++star)
			cout << "* ";
		cout << endl;
	}

	return 0;
}