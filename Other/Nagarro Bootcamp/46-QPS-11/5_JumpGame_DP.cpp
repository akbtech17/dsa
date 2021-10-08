// 5_JumpGame_DP.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printV(vector<bool> dp) {
        for(auto el : dp) cout<<el<<" ";
        cout<<endl;
        return;
    }
	bool canJump(vector<int> nums) {
        int n = nums.size();
        vector<bool> dp(n,false);		
        dp[0] = true;

        for(int i=n-2; i>=0; i--) {
        	// dp[n-i+1] 
        	int ci = n-i-1;
            cout<<ci<<"::";
        	int csteps = nums[i];
            cout<<csteps;
            for(int step=1; step<=csteps and step<=ci; step++) {
                dp[ci] = dp[ci] or dp[ci-step];
            }
        	
        }
        cout<<endl;
        printV(dp);
        return dp[n-1];
    }
};

int main() {
	Solution S;
	// cout<<S.canJump({2,3,1,1,4})<<endl;
    // cout<<S.canJump({3,2,1,0,4})<<endl;
	cout<<S.canJump({2,0})<<endl;

	return 0;
}