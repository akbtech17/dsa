// unique - numer - 2.cpp
#include <iostream>
#define MX 10000
using namespace std;

int main() {
	int n = 0;
	int arr[MX] = {0};
	int xrNum = 0; //store xor of all numbers

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		xrNum ^= arr[i];
	}

	//finding the different bit postion
	int temp = xrNum;
	int bitPos = 0;
	while ((temp & 1) != 1) {
		bitPos++;
		temp = temp >> 1;
	}

	int setContainingBit = 0;

	//making the mask for the diff bit, to seperate the sets
	int mask = (1 << bitPos);
	//seperating the sets
	for (int i = 0; i < n; ++i) {
		if ((mask & arr[i]) == 0) setContainingBit ^= arr[i];
	}

	//printing the unique numbers...
	cout << setContainingBit << " " << (xrNum ^ setContainingBit);

	return 0;
}