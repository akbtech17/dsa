// factorial - of - large - numbers.cpp
#include <iostream>
#define MX 500
using namespace std;

int multiply(int *fact, int n , int num) {

	int carry = 0;

	for (int i = 0; i < (n); ++i)
	{
		int prod = (fact[i] * num) + carry;
		carry = prod / 10;
		fact[i] = prod % 10;
	}

	while (carry) {
		fact[n] = (carry % 10);
		carry = carry / 10;
		n++;
	}
	return n;
}

int main()
{
	int number;
	cin >> number;

	int fact[MX] = {0};
	fact[0] = 1;
	int n = 1;

	for (int i = 2; i <= number; ++i)
	{
		n = multiply(fact, n, i);
	}
	// cout << n;

	//print the ans
	for (int i = n - 1; i >= 0 ; --i) cout << fact[i];

	return 0;
}