// 6-SquaresOfSortedArray.cpp


//Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

#include<bits/stdc++.h>
using namespace std;
	
vector<int> sortedSquares(vector<int>& nums) {
   	for(int i=0; i<nums.size(); i++) {
     	nums[i] *= nums[i];
   	}
   	sort(nums.begin(),nums.end());
    return nums;
}

int main() {
	vector<int> nums({-4,-1,0,3,10});
	nums = sortedSquares(nums);

	for(auto el : nums) cout<<el<<" ";
	return 0;
}