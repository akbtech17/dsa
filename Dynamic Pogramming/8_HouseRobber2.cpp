// 39_HouseRobber2.cpp
// https://leetcode.com/problems/house-robber-ii/
// https://ide.codingblocks.com/s/639629

// Approach - BU DP
// TC - O(N)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int house_robber_1(vector<int> &nums) {
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
    int rob(vector<int> nums) {
        // important edge cases
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

    	// we will use the House Robber 1 technique,
    	// there will be two cases, 

    	// 1. if we include the robbing of first house in our ans,
    	//    then the last house cant be robbed in any case.
    	vector<int> v1(nums.begin(), nums.end()-1);
    	int ans1 = house_robber_1(v1);

    	// 2. if we include the robbing of last house in our ans,
    	//    then the first house cant be robbed in any case.
    	vector<int> v2(nums.begin()+1, nums.end());
    	int ans2 = house_robber_1(v2);

    	// and our final ans will be max of these two cases
    	return max(ans1, ans2);
    }
};


int main() {
	Solution S;
	cout<<S.rob({2,3,2})<<endl;
	cout<<S.rob({1,2,3,1})<<endl;

	return 0;
}