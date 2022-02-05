// 4_SubarrayWithEqual01.cpp
// Question Link - https://leetcode.com/problems/contiguous-array/
// Solution Link - https://ide.codingblocks.com/s/654224
// Resource - https://www.youtube.com/watch?v=6PAj5F9O4gU&t=690s
#include <bits/stdc++.h>
using namespace std;

// A1: Bruteforce
// TC: O(N^3)
// SC: O(1)

// A2: Using CSum
// TC: O(N^2)
// SC: O(a1)

// A3: Using HMap and CSum
//     0 -> -1
//     1 ->  1
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int,int> mp;
        int sum = 0;

        mp[0] = -1;   // most important case
        
        for(int i=0; i<n; i++) {
        	// 0 -> -1
			// 1 ->  1
            sum += nums[i] == 1 ? 1 : -1;
            if(mp.count(sum) == 0) mp[sum] = i;
            else ans = max(ans,i-mp[sum]);
        }
        
        return ans;
    }
};