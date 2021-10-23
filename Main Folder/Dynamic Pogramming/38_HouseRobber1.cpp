// 38_HouseRobber1.cpp
// https://leetcode.com/problems/house-robber/
// https://ide.codingblocks.com/s/639628

// Approach - BU DP
// for each house,
// if we rob the house p1 = house[i]+dp[i-2]
// else p2 = dp[i-1]
// so, dp[i] = max(house[i],dp[i-2], dp[i-1])

// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++) {
            int ph1 = 0, ph2 = 0;
            if(i-1>=0) ph1 = dp[i-1];            
            if(i-2>=0) ph2 = dp[i-2];
            
            dp[i] = max(ph2+nums[i], ph1);
        }
        return dp[n-1];  
    }
};


int main() {
	Solution S;
	cout<<S.rob({1,2,3,1})<<endl;
	cout<<S.rob({2,7,9,3,1})<<endl;

	return 0;
}