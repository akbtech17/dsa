// 7_BinarySearchInSortedRotatedArray.cpp
// Problem Link - https://leetcode.com/problems/search-in-rotated-sorted-array/
// Code Link - https://ide.codingblocks.com/s/639321
#include <bits/stdc++.h>
using namespace std;

// Approach: Recursive
// TC: O(LogN)
// SC: O(LogN)
class Solution {
public:
    int recurse(int s, int e, int key, vector<int>& nums) {
        // Base Case - 
        // If there is no element to search, just return -1.
        if(s > e) return -1;
        
        // Recursive Cases - 
        // 1. Check if mid element is our key.
        int mid = s+(e-s)/2;
        if(nums[mid] == key) return mid;
        
        // 2. Check if the mid lies on the first sorted line.
        if(nums[s]<=nums[mid]) {
        	// 2.1 Check if the key falls under the extreme limits of the found sorted line.
            if(nums[s]<=key and key<=nums[mid]) return recurse(s,mid-1,key,nums);
            // 2.2 If no, recurse for the other part.
            else return recurse(mid+1,e,key,nums);
        }
        
        // 3. Here means, mid lies on the second sorted line.
        // 3.1 Check if the key falls under the extreme limits of the found sorted line.
        if(nums[mid]<=key and key<=nums[e]) return recurse(mid+1,e,key,nums);
        // 3.2 If no, recurse for the other part.
        return recurse(s,mid-1,key,nums);
    }
    int search(vector<int> nums, int target) {
        return recurse(0,nums.size()-1,target,nums);
    }
};

int main() {
	Solution S;
	cout<<S.search({4,5,6,7,0,1,2},0)<<endl;
	cout<<S.search({4,5,6,7,0,1,2},3)<<endl;
	cout<<S.search({1},0)<<endl;

	return 0;
}

