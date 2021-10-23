// 5_LowerBound.cpp
// https://ide.codingblocks.com/s/639501

// TC - O(LogN) 
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
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

int main() {
	Solution S;
	cout<<S.findLowerBound({1,2,3,4,5,5,5,5,9,10},5)<<endl;

	return 0;
}

