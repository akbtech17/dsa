// 41_DeleteAndEarn.cpp
// https://leetcode.com/problems/delete-and-earn/
// https://ide.codingblocks.com/s/648077
#include <bits/stdc++.h>
using namespace std;

// Approach - 1D BU DP
// TC - O(N)
// SC - O(N)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001, 0);
        
        for(auto el : nums) {
            v[el]++;
        }
        int take = 0, skip = 0;
        for(int i=0; i<v.size(); i++) {
            // case1: if we take the ith el
            int takei = (v[i]*i)+skip;
            // case2: if we skip the ith el
            int skipi = max(take,skip);
            
            take = takei;
            skip = skipi;
        }
        
        return max(take,skip);
    }
};

int main() {

}