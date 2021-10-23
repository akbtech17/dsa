// 8_BinarySearchInSortedRotatedArray2.cpp
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// TC - O(N) Worst, O(LogN + C) Average
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

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
        
        // 2. Check if there is the constant line, 
        // means if there is nothing to search for...
        if(nums[s] == nums[mid] and nums[mid] == nums[e]) return recurse(s+1,e-1,key,nums);
        
        // 3. Check if the mid lies on the first sorted line.
        if(nums[s]<=nums[mid]) {
        	// 3.1 Check if the key falls under the extreme limits of the found sorted line.
            if(nums[s]<=key and key<=nums[mid]) return recurse(s,mid-1,key,nums);
            // 3.2 If no, recurse for the other part.
            else return recurse(mid+1,e,key,nums);
        }
        
        // 4. Here means, mid lies on the second sorted line.
        // 4.1 Check if the key falls under the extreme limits of the found sorted line.
        if(nums[mid]<=key and key<=nums[e]) return recurse(mid+1,e,key,nums);
        // 4.2 If no, recurse for the other part.
        return recurse(s,mid-1,key,nums);
    }
    bool search(vector<int> nums, int target) {
        return recurse(0,nums.size()-1,target,nums) != -1;
    }
};

int main() {
	Solution S;
	cout<<S.search({2,5,6,0,0,1,2},0)<<endl;
	cout<<S.search({2,5,6,0,0,1,2},3)<<endl;
	return 0;
}

