// 1-SquaresOfSortedArrays.cpp

//Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

#include<bits/stdc++.h>
using namespace std;
	
// nlogn
vector<int> sortedSquares(vector<int>& nums) {
   	for(int i=0; i<nums.size(); i++) {
     	nums[i] *= nums[i];
   	}
   	sort(nums.begin(),nums.end());
    return nums;
}

// linear time- using two pointer and merge array
vector<int> sortedSquares2(vector<int>& nums) {
   	int i = -1;
   	int j = 0;
   	int n = nums.size();
   	while(i+1<n and nums[i+1]<0) i++;
   	j = i+1;
   	vector<int> ans;
    // cout<<i<<j<<endl;
   	while(j<n and i>=0) {
   		if(nums[j]<(-1)*nums[i]) {
   			ans.push_back(nums[j]*nums[j]);
   			j++;
   		}
   		else {
   			ans.push_back(nums[i]*nums[i]);
   			i--;
   		}
   	}

    while(i>=0) {
        ans.push_back(nums[i]*nums[i]);
        i--;
    }

    while(j<n) {
        ans.push_back(nums[j]*nums[j]);
        j++;
    }
    return ans;
}

// impletation in other style
vector<int> sortedSquares3(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n-1;
    vector<int> ans(n);

     for(int idx=n-1;idx>=0;idx--) {
        nums[idx] *= nums[idx];
    } 
    int idx = n-1;
    while(i<=j) {
        if(nums[i]>nums[j]) ans[idx] = nums[i++];
        else ans[idx] = nums[j--];
        idx--;
    }     
    return ans;
}

int main() {
  vector<int> nums({-4,-1,0,3,10});
	// vector<int> nums({-1});
	nums = sortedSquares3(nums);

	for(auto el : nums) cout<<el<<" ";
	return 0;
}