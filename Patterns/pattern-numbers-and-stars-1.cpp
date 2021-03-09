// pattern - numbers - and - stars - 1.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int row = 1; row <= n; ++row) {
		//numbers
		for (int num = 1; num <= n - row + 1; num++) cout << num << " ";
		//stars
		for (int stars = 1; stars <= ((row - 1) * 2 - 1); stars++) cout << "* ";
		cout << endl;
	}

	return 0;
}