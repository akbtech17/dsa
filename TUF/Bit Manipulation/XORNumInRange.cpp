#include <iostream>
using namespace std;

// Approach1 - Bruteforce
// TC: O(R-L) ~ O(N)
// SC: O(1)
class Solution {
public:
	int findRangeXOR(int l, int r) {
		int ans = 0;
		for (int num = l; num <= r; num++)
			ans ^= num;
		return ans;
	}
};

// Approach2 - Optimized
// TC: O(1)
// SC: O(1)
class Solution {
public:
	int XORTillN(int n) {
		if (n % 4 == 1)
			return 1;
		else if (n % 4 == 2)
			return n + 1;
		else if (n % 4 == 3)
			return 0;
		return n;
	}

	// XOR(L to R) = XOR(1 to L-1) ^ XOR(1 to R)
	int findRangeXOR(int l, int r) {
		return XORTillN(l - 1) ^ XORTillN(r);
	}
};