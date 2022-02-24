// 34_MajorityElement_Nby2.cpp
// Problem Link - https://leetcode.com/problems/majority-element/
// Code Link - https://ide.codingblocks.com/s/656092
// Resource - https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
#include <bits/stdc++.h>
using namespace std;

// A1: Bruteforce (TLE)
// TC: O(N^2)
// SC: O(1) 
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nBy2 = n/2;

        for (int i=0; i<n; i++) {
            int cnt = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == nums[i])cnt++;
            }
            if (cnt > nBy2) return nums[i];
        }

        return -1;
    }
};


// A2: Using Map 
// TC: O(N)
// SC: O(N) 
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nBy2 = n/2;
        unordered_map<int,int> mp;
        
        for(auto el: nums) mp[el]++;
        
        int ans = -1;
        
        for(auto p : mp) if(p.second > nBy2) return p.first;
        
        return -1;
    }
};


// A3: Boyer-Moore Majority Vote Algorithm
// TC: O(2N)
// SC: O(1) 
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int nBy2 = nums.size()/2; // it can be nByK
        int candidate;
        
        for(int i=0; i<nums.size(); i++) {
            if(cnt == 0) candidate = nums[i];  // mark the curr as cand
            if(nums[i] == candidate) cnt++;    // inc count
            else cnt--;                        // dec cnt
        }
        

        // check if the found el's fre is greater than req cnt
        int freOfCand = 0;
        for(auto el: nums) if(el == candidate) freOfCand++;
        
        if(freOfCand > nBy2) return candidate;

    	// else return -1
        return -1;
    }
};


int main() {
	return 0;
}