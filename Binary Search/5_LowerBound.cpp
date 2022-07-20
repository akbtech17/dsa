// 5_LowerBound.cpp
// Problem Link - https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
// Code Link - https://ide.codingblocks.com/s/639501
#include <bits/stdc++.h>
using namespace std;

// A1: Recursive
// TC: O(LogN) 
// SC: O(1)
class Solution1 {
public:
    int recurse(int s, int e, int key, vector<int>& nums) {
        int ans = -1;
        while(s<=e) {
        	int mid = s+(e-s)/2;
        	if(nums[mid] == key) {
        		ans = mid;
        		e = mid-1;
        	}
        	else if(key < nums[mid]) e = mid-1;
        	else s = mid+1;
        }
        return ans;
    }
    int findLowerBound(vector<int> nums, int target) {
        return recurse(0,nums.size()-1,target,nums);
    }
};


// A2: Inbuilt Function
// TC: O(LogN) 
// SC: O(1)
class Solution2 {
public:
    int findLowerBound(vector<int> nums, int target) {
        int pos = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return 
            pos >= nums.size()
            ? -1
            : nums[pos] != target
            ? -1
            : pos;
    }
};

int main() {
	Solution2 S;
	cout<<S.findLowerBound({1,2,3,4,5,5,5,5,9,10},6)<<endl;

	return 0;
}

