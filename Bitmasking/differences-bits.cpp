// differences - bits.cpp
#include <iostream>
using namespace std;

int setBits(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt++;
		n = n & (n - 1);
	}
	return cnt;
}

int findDiffBits(int a, int b) {
	int count = 0;
	int xr = a ^ b;
	return setBits(xr);
}

int main()
{
	cout << findDiffBits(5, 2);
	return 0;
}