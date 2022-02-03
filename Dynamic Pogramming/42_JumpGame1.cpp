// 42_JumpGame1.cpp
// https://leetcode.com/problems/jump-game/
// https://ide.codingblocks.com/s/648081
#include <bits/stdc++.h>
using namespace std;

// Approach - 1D BU DP
// TC - O(1)
// SC - O(N)
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int cidx = 0;
        int max_idx_reach = 0;
        int n = nums.size();
        
        
        while(cidx<n and cidx<=max_idx_reach) {
            max_idx_reach = max(nums[cidx] + cidx,max_idx_reach);
            cidx++;
        }
        
        return cidx == n;
    }
};

int main() {

}