// 3_MoveZeroes.cpp
// https://leetcode.com/problems/move-zeroes/
// https://ide.codingblocks.com/s/635358

#include <bits/stdc++.h>
using namespace std;

// Approach - 2 Pointers
// TC - O(N)
// SC - O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0) {
                nums[s++] = nums[i];
            }
        }
        
        while(s<nums.size()) nums[s++] = 0;
    }
};