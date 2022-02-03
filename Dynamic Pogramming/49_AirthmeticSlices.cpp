// 49_AirthmeticSlices.cpp
// https://leetcode.com/problems/arithmetic-slices/
// https://ide.codingblocks.com/s/642102

#include <bits/stdc++.h>
using namespace std;

// Approach1 - 1D BU DP
// we need to find the number of AP's suarrays, >=0
// we'll maintain the dp[i] -> no of AP's ending at nums[i]
// at the last we will take the sum of dp[]

// TC - O(N)
// SC - O(N)
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

// Approach2 
// TC - O(N)
// SC - O(1)
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