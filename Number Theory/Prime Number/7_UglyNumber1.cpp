// 7_UglyNumber.cpp
// https://leetcode.com/problems/ugly-number/
// https://ide.codingblocks.com/s/640051

// Approach - if we are able to reduce number to 1, by dividing
// number using 2,3,4,5 then it is an ugly number, else if rem != 1
// then return false!

// TC - O(Log2(N) + Log3(N) + Log4(N) + Log5(N)) = O(Log5(N))
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        for(int i=2; i<6 and n; i++) {
            while(n%i == 0) n /= i;
        }
        return n ==1;
    }
};
int main() {
	Solution S;
	cout<<S.isUgly(6)<<endl;
    cout<<S.isUgly(8)<<endl;
    cout<<S.isUgly(14)<<endl;
	cout<<S.isUgly(1)<<endl;

	return 0;
}