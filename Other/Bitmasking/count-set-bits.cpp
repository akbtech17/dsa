// count - set - bits.cpp
#include <iostream>
using namespace std;

//TC - total number of bits in a number = (logn+1)
//SC - 1
int countSetBits(int num) {
	int ans = 0;

	while (num > 0) {
		int lastBit = (num & 1);
		ans += lastBit;
		//right shift the number
		num = num >> 1;
	}

	return ans;
}


//TC - total number of set-bits in a number
//SC - 1
//Brian Kernighan’s Algorithm
int countSetBits2(int num) {
	int ans = 0;

	while (num > 0) {
		ans++;
		num = (num & (num - 1));
	}

	return ans;
}

int main() {
	int num;
	cin >> num;

	cout << countSetBits(num) << " ";
	cout << countSetBits2(num);

	return 0;
}