// SquaresOfASortedArray.cpp
// https://leetcode.com/problems/squares-of-a-sorted-array/
// https://ide.codingblocks.com/s/635300

#include <bits/stdc++.h>
using namespace std;

// Approach - Recursive
// TC - O(NLogN)
// SC - O(1)
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};


// Approach - Using Two Pointers and Merging Two Sorted Arrays
// TC - O(N)
// SC - O(1)
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int i = -1;
   	int j = 0;
   	int n = nums.size();
   	while(i+1<n and nums[i+1]<0) i++;
   	j = i+1;
   	vector<int> ans;

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
};

// Approach - Using Two Pointers and Merging Two Sorted Arrays (Other Style)
// TC - O(N)
// SC - O(1)

// after squaring, there will be a +ve parabola of values formed
// -   -
//  - -
//   -
// and then we will try to pick the values from the extreme ends
// and try to place them in desc order
class Solution3 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            nums[i] *= nums[i];
        }
        
        vector<int> ans(nums.size());
        int s = 0;
        int e = nums.size()-1;
        int i = e; 
        while(s<=e) {
            if(nums[s] > nums[e]) {
                ans[i--] = nums[s];
                s++;
            }
            else {
                ans[i--] = nums[e];
                e--;
            }
        }
        return ans;
    }
};