// 19_PowerOfTwo.cpp
// https://leetcode.com/problems/power-of-two/
// https://ide.codingblocks.com/s/648024
#include <bits/stdc++.h>
using namespace std;

// Approach - Bitmasking
// TC - O(1)
// SC - O(1)

// every power of 2 is of the form 10...0
// so if we do and with            01...1
// and if it gives 0 then we know it is
// the power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 and !(n&(n-1));
    }
};

int main() {
 	Solution S;
 	cout<<S.isPowerOfTwo(2)<<endl;
 	cout<<S.isPowerOfTwo(3)<<endl;
 	cout<<S.isPowerOfTwo(4)<<endl;
 	cout<<S.isPowerOfTwo(5)<<endl;

 	return 0;
}