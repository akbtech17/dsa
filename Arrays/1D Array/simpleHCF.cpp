// simpleHCF.cpp
#include <iostream>
#include <climits>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int findHCF(int arr[], int n) {
	int hcf = arr[0];
	for (int i = 1; i < n; ++i)
	{
		hcf = gcd(arr[i], hcf);
		if (hcf == 1)
			return 1;
	}
	return hcf;
}

int main() {
	int n, arr[15];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << findHCF(arr, n);
	return 0;
}