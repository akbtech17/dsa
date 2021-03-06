// missing_number_2.cpp
#include <iostream>
#define MX 100000
using namespace std;

int main() {
	int n;
	int arr[MX] = {0};

	cin >> n;
	int xorNums = 0;
	for (int i = 0; i < n - 2; i++) {
		cin >> arr[i];
		xorNums ^= arr[i];
	}

	for (int i = 1; i <= n; ++i)
		xorNums ^= i;

	int bitPos = 0;
	int temp = xorNums;

	while ((temp & 1) != 1) {
		bitPos++;
		temp = temp >> 1;
	}

	int s1 = 0;
	int s2 = 0;

	//making the mask for the diff bit, to seperate the sets
	int mask = (1 << bitPos);
	//seperating the sets
	for (int i = 1; i <= n ; ++i) {
		if ((mask & i) == 0) s1 ^= i;
		else s2 ^= i;
	}

	for (int i = 0; i < n - 2 ; ++i) {
		if ((mask & arr[i]) == 0) s1 ^= arr[i];
		else s2 ^= arr[i];
	}

	//printing the unique numbers...
	cout << s1 << " " << s2;

	return 0;
}