// 10_MinPivotElementInSortedRotatedArray.cpp
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://ide.codingblocks.com/s/639485

// TC - O(LogN) 
// SC - O(LogN)
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // function to find the index of max element in the 
    // sorted rotated array,
    int recurse(int s, int e, vector<int>& nums) {
        // Base Case - 
        // If there is no element to search, just return -1.
        if(s > e) return -1;
        
        // Recursive Cases - 
        int mid = s+(e-s)/2;
        if(mid<e and nums[mid] > nums[mid+1]) return mid;
        if(mid>s and nums[mid-1] > nums[mid]) return mid-1;
       	
       	// 1. if mid lies on the first line, so search in right part
    	if(nums[s] <= nums[mid]) return recurse(mid+1,e,nums);
    	// 2. else mid lies on the second line, so search in left part
        return recurse(s,mid-1,nums);
    }
    int findMin(vector<int> nums) {
        int n = nums.size();
        int ansi = recurse(0,nums.size()-1,nums);
        if(ansi == -1) return nums[0];
        return nums[ansi+1];
    }
};

int main() {
	Solution S;
	cout<<S.findMin({3,4,5,1,2})<<endl;
	cout<<S.findMin({4,5,6,7,0,1,2})<<endl;
	cout<<S.findMin({11,13,15,17})<<endl;

	return 0;
}

