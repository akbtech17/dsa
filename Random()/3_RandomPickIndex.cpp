// 3_RandomPickIndex.cpp
// Question - https://leetcode.com/problems/random-pick-index/
// Code - https://ide.codingblocks.com/s/649957
#include <bits/stdc++.h>
using namespace std;

// Approach - using Rand(), vector and hmap
// TC - O(1)
// SC - O(N)
class Solution {
    map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = mp[target].size();
        return mp[target][rand()%n];
    }
};