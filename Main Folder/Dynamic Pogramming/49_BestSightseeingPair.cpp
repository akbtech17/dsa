// 49_BestSightseeingPair.cpp
// https://leetcode.com/problems/best-sightseeing-pair/
// https://ide.codingblocks.com/s/642036

#include<bits/stdc++.h>
using namespace std;

// Approach1 - Bottom Up 
// we have to maximize score[i]+score[j]+j-i
// so we have to track the max (score[i]+i) before each cell,
// so that we could make the best pair if we choose to include the current cell,

// dp[i] = max of 
// 1. dp[i-1] ie, best pair that have been occured before ith
// 2. score[i]-j+mx ie, pair ending at ith location, 
// TC - O(N
// SC - O(N)
class Solution1 {
public:
    int maxScoreSightseeingPair(vector<int> values) {
        int n = values.size();
        vector<int> dp(n,0);
        int mx_sf = values[0];   // max i+vals[i]
        for(int i=1; i<n; i++) {
            dp[i] = max(dp[i-1], mx_sf + values[i] - i);
            mx_sf = max(mx_sf, values[i] + i);
        }
        return dp[n-1];
    }
};

// Approach2 - Buttom Up
// TC - O(N)
// SC - O(1)
class Solution2 {
public:
    int maxScoreSightseeingPair(vector<int> values) {
        int n = values.size();
        int prev_best = 0;       // storing the prev best pair's score
        int mx_sf = values[0];   // max i+vals[i]
        int ans;
        for(int i=1; i<n; i++) {
            ans = max(prev_best, mx_sf + values[i] - i);
            mx_sf = max(mx_sf, values[i] + i);
            prev_best = ans;
        }
        return ans;
    }
};


int main() {
	Solution1 S1;
	Solution2 S2;
	
	cout<<S1.maxScoreSightseeingPair({8,1,5,2,6})<<endl;
	cout<<S1.maxScoreSightseeingPair({1,2})<<endl;

	cout<<S2.maxScoreSightseeingPair({8,1,5,2,6})<<endl;
	cout<<S2.maxScoreSightseeingPair({1,2})<<endl;
	
	return 0;
}