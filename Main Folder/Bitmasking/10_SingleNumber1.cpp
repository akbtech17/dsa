// 10_SingleNumber1.cpp
// https://leetcode.com/problems/single-number/
// https://ide.codingblocks.com/s/642416
#include<bits/stdc++.h>
using namespace std;

// Approach - Using XOR
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int singleNumber(vector<int> nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) 
        	ans ^= nums[i];
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.singleNumber({2,2,1})<<endl;
	cout<<S.singleNumber({4,1,2,1,2})<<endl;
	cout<<S.singleNumber({1})<<endl;

	return 0;
}