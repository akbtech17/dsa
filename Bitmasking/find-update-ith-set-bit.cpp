// find - update - ith - set - bit.cpp
#include <iostream>
using namespace std;

int ithBit(int num, int i) {
	int ans;

	int mask = 1;
	mask = mask << i;

	return (num & mask);
}

int main() {
	int num, i;
	cin >> num >> i;

	cout << i << "th bit of " << num << ithBit(num, i) << endl;

	return 0;
}