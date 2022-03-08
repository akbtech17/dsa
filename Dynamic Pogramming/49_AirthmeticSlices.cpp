// 49_AirthmeticSlices.cpp
// Problem Link - https://leetcode.com/problems/arithmetic-slices/
// Code Link - https://ide.codingblocks.com/s/642102
// Resource Link - https://www.youtube.com/watch?v=rSi4MpGEz1M&ab_channel=Pepcoding
#include <bits/stdc++.h>
using namespace std;

// A1: 1D BU DP
// we need to find the number of AP's subarrays, >= 3
// we'll maintain the dp[i] -> no of AP's ending at nums[i]
// at the last we will take the sum of dp[0->n]

// 0 - suppose the diff between i and i+1 el is d
//     so the diff bw any two consecutive el must be d
//     in short they want us to find number of AP subarrays that
//     can be formed using nums array
// 1 - nums.size() < 3 makes 0 APs
// 2 - store number of APs ending at i-idx[inclusive]
// 3 - dp[i] = dp[i-1] (all AP ending at i-1 idx will grow) + 1 (1 new AP will be born of size 3)

// TC: O(N)
// SC: O(N)
class Solution1 {
public:
    int numberOfArithmeticSlices(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        int ans = 0;
        for(int i=2; i<n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]) {
            	dp[i] = 1+dp[i-1];
            	ans += dp[i];
            }
                
            else dp[i] = 0;
        } 
        return ans;
    }
};

// A2: Using variable, instead of dp[]
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    int numberOfArithmeticSlices(vector<int> nums) {
        int n = nums.size();
        int prev = 0;

        int ans = 0;
        for(int i=2; i<n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1]-nums[i-2]) {
            	prev++;
            	ans += prev;
            }    
            else prev = 0;
        } 
        return ans;
    }
};

int main() {
	Solution1 S1;
	Solution2 S2;
	
	cout<<S1.numberOfArithmeticSlices({1,2,3,4})<<endl;
	cout<<S1.numberOfArithmeticSlices({1,2,3,4,5})<<endl;
	cout<<S1.numberOfArithmeticSlices({1})<<endl;
	cout<<S1.numberOfArithmeticSlices({1,2,3,8,9,10})<<endl;

	cout<<S2.numberOfArithmeticSlices({1,2,3,4})<<endl;
	cout<<S2.numberOfArithmeticSlices({1,2,3,4,5})<<endl;
	cout<<S2.numberOfArithmeticSlices({1})<<endl;
	cout<<S2.numberOfArithmeticSlices({1,2,3,8,9,10})<<endl;

	return 0;
}