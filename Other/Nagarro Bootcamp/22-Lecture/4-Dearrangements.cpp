// 28Dearrangements.cpp

#include <iostream>
using namespace std;

int solve(int n) {
	//base case
	if (n <= 1) return 0;
	if (n == 2) return 1;
	//recursive case
	return (n - 1) * (solve(n - 1) + solve(n - 2));
}

int main() {
	cout << solve(2) << endl;
	cout << solve(3) << endl;
	cout << solve(4) << endl;
	cout << solve(5) << endl;

	return 0;
}