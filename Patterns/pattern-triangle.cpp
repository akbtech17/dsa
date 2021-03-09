// pattern - triangle.cpp
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int row = 1; row <= n; ++row)	{
		//spaces
		for (int spaces = 1; spaces <= n - row; ++spaces)
			cout << "\t";
		//increasing number
		for (int num = row; num < row + row; ++num) cout << num << "\t";
		//decreasing number
		for (int num = row + row - 2; num >= row; --num) cout << num << "\t";
		cout << endl;
	}
}