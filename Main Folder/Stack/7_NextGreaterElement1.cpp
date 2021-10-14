// 7_NextGreaterElement1.cpp
// https://leetcode.com/problems/next-greater-element-i/
// https://ide.codingblocks.com/s/636020

// Approach - Stack and HashMap
// TC - O(nums1.length + nums2.length)
// SC - O(N)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> NGR(vector<int> &nums) {
        stack<int> stk;
        int n = nums.size();
        
        vector<int> ans(n,-1);
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() and stk.top() < nums[i]) 
                stk.pop();
            ans[i] = stk.empty() ? -1 : stk.top();
            stk.push(nums[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans, ngr = NGR(nums2);
        unordered_map<int,int> mp;
        for(int i=0; i<nums2.size(); i++) mp[nums2[i]] = i;
        
        for(auto el : nums1) {
            ans.push_back(ngr[mp[el]]);
        }
        
        return ans;
    }
};