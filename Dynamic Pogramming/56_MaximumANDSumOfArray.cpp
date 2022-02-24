// 56_MaximumANDSumOfArray.cpp
class Solution {
private:
    int solve(int idx, vector<int> &nums, vector<int> &wt, int numSlots, map<pair<int,vector<int>>, int> &dp) {
        
        if(idx == nums.size()) return 0;
        
        if(dp.find({idx,wt}) != dp.end()) return dp[{idx,wt}];
        
        // try to put this arr[idx] into every slot from 
        // 1 to numSlots
        int maxi = INT_MIN;
        for(int k=1; k<=numSlots; k++) {
            // i can put if it is not full yet
            if(wt[k]<2) {
                // i can put element
                wt[k]++;
                int ans = (nums[idx] & k) + solve(idx+1,nums,wt,numSlots,dp);
                wt[k]--;
                maxi = max(maxi,ans);
            }
        }
        return dp[{idx,wt}] = maxi;
    }    
public:
    Solution() {}
    
    
    
    int maximumANDSum(vector<int>& nums, int numSlots) {
        map<pair<int,vector<int>>, int> dp;
        vector<int> wt(numSlots+1,0);
        return solve(0, nums, wt, numSlots, dp);
    }
};