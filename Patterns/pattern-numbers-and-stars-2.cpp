// pattern - numbers - and - stars - 2.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int row = 1; row <= n; ++row) {
		//numbers
		for (int num = 1; num <= row; num++) cout << num ;
		//stars
		for (int stars = 1; stars <= (n - row); stars++) cout << "*";
		cout << endl;
	}

	return 0;
}