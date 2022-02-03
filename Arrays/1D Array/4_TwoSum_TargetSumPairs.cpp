// 4_TwoSum_TargetSumPairs.cpp
// https://leetcode.com/problems/two-sum/
// https://ide.codingblocks.com/s/635350

#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Bruteforce
// TC - O(N^2)
// SC - O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
        	for(int j=0; j<n; j++) {
        		if(i != j and nums[i]+nums[j] == target) 
        			return vector<int>({i,j});
        	}
        }
        return vector<int>({});
    }
};

// Approach 2 - 2 Pointers
// TC - O(N)
// SC - O(1)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums2;
        for(int i=0;i<nums.size();i++) {
            nums2.push_back({nums[i],i});    
        }
        sort(nums2.begin(),nums2.end());
        int n = nums.size();
        int s = 0;
        int e = n-1;
        
        while(s<e) {
            int csum = nums2[s].first+nums2[e].first;
            
            if(csum == target)
                return vector<int>({nums2[s].second,nums2[e].second});
   			else if(csum < target) s++;
            else e--;
        }
        return vector<int>({});
    }
};