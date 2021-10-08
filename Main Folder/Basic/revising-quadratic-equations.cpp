// revising - quadratic - equations.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int d = (b * b) - (4 * a * c);

	if (d > 0) {
		cout << "Real and Distinct";
		int root1 = 0;
		int root2 = 0;
		d = sqrt(d);
		cout << "determinant : " << d;
		root1 = (-b + d) / (2 * a);
		root2 = (-b - d) / (2 * a);
		cout << endl;
		if (root1 < root2) cout << root1 << " " << root2;
		else cout << root2 << " " << root1;
	}
	else if (d < 0) {
		cout << "Imaginary";
	}
	else {
		cout << "Real and Equal";

		int root = (-b) / (2 * a);

		cout << endl << root << " " << root;
	}

	// cout << pow(-11, 2) << " ";
	// cout << (-11)*(-11);

	return 0;
}