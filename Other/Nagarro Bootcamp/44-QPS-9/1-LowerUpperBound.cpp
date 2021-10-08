// 1-LowerUpperBound.cpp
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int target) {
	int s = 0;
	int e = nums.size()-1;
	int ans = -1;
	while(s<=e) {
		int mid = (s+e)/2;
		if(nums[mid] == target) {
			ans = mid;
			e = mid-1;
		}
        else if(nums[mid]>target) e = mid-1;
		else s = mid+1;
	}

	return ans;
}

int upperBound(vector<int> &nums, int target) {
	int s = 0;
	int e = nums.size()-1;
	int ans = -1;
	while(s<=e) {
		int mid = (s+e)/2;
		if(nums[mid] == target) {
			ans = mid;
            s = mid+1;
		}
        else if(nums[mid]<target) s = mid+1;
		else e = mid-1;
	}

	return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
	// int lb = lowerBound(nums,target);
	// int ub = upperBound(nums,target);

	auto lb_itr = lower_bound(nums.begin(),nums.end(),target);
	auto ub_itr = upper_bound(nums.begin(),nums.end(),target);
	
    if(lb_itr == nums.end()) return {-1,-1};    
    if(*lb_itr != target) return {-1,-1};

    
    int lb = lb_itr - nums.begin();    
    int ub = ub_itr - nums.begin() -1;    
    
	return {lb, ub};
}

