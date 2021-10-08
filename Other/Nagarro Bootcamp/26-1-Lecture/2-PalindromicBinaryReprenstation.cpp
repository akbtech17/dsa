// 2 - PalindromicBinaryReprenstation.cpp
#include <iostream>
using namespace std;

bool isTheKthBitSet(int num, int k) {
	return num & (1 << k);
}

bool isPalindrome(int num) {
	unsigned int hi = sizeof(unsigned int) * 8 - 1; //at the 32th bit //31st index
	unsigned int lo = 0;

	while (lo < hi) {
		if (isTheKthBitSet(num, lo) != isTheKthBitSet(num, hi))
			return false;
		lo++;
		hi--;
	}
	return true;
}

void tellPalindrome(unsigned int num) {
	if (isPalindrome(num)) cout << num << " yes\n";
	else cout << num << " no\n";
	return;
}

int main() {
	unsigned int x = 1 << 31; // 2^31 1000....0
	unsigned int y = 1 << 30; // 2^30 01000..00
	tellPalindrome(x);
	tellPalindrome(y);
	x += 1; // 2^31 + 1 1000....1
	y += 2; // 2^30 + 1 0100...10
	tellPalindrome(x);
	tellPalindrome(y);
	return 0;
}