// 6_UpperBound.cpp
// Problem Link - https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
// Code Link - https://ide.codingblocks.com/s/639502
#include <bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC: O(LogN) 
// SC: O(1)
class Solution {
public:
    int recurse(int s, int e, int key, vector<int>& nums) {
        int ans = -1;
        while(s<=e) {
        	int mid = s+(e-s)/2;
        	if(nums[mid] == key) {
        		ans = mid;
        		s = mid+1;
        	}
        	else if(key < nums[mid]) e = mid-1;
        	else s = mid+1;
        }
        return ans;
    }
    int findUpperBound(vector<int> nums, int target) {
        return recurse(0,nums.size()-1,target,nums);
    }
};

// A2: Inbuilt Function
// TC: O(LogN) 
// SC: O(1)
class Solution2 {
public:
    int findUpperBound(vector<int> nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target)) return -1;
        int pos = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        return pos-1;
    }
};

int main() {
	Solution2 S;
	cout<<S.findUpperBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;

	return 0;
}

