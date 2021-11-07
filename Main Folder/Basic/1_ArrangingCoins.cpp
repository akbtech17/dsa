// 1_ArrangingCoins.cpp
// https://leetcode.com/problems/arranging-coins/
// https://ide.codingblocks.com/s/642414
#include <bits/stdc++.h>
using namespace std;

// Approach - Bruteforce
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int k = 1;
        while(k<=n) {
            n -= k;
            k++;
        }
        return k-1;
    }
};

int main() {
	Solution S;
	cout<<S.arrangeCoins(5)<<endl;
	cout<<S.arrangeCoins(8)<<endl;

	return 0;
}