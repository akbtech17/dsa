// 1_SubarraySumK.cpp
// https://leetcode.com/problems/subarray-sum-equals-k/
// https://ide.codingblocks.com/s/632632

#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2)
// SC - O(n)
class Solution {
public:
    int subarraySum(vector<int> nums, int k) {
        vector<int> csum;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(i == 0) csum.push_back(nums[i]);
            else csum.push_back(nums[i]+csum[i-1]);
        }
        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int cs = csum[j];
                if(i>0) cs -= csum[i-1];
                if(cs == k) count++;
            }
        }   
        return count;
    }
};


// TC - O(n)
// SC - O(n)
// Approach - While Building CSUM
// check if the csum[i]-k subarray sum frequency, and add it in our ans.
class Solution2 {
public:
    int subarraySum(vector<int> nums, int k) {
        int count = 0;
       	unordered_map<int,int> mp;
       	mp[0] = 1;
       	int csum = 0;
       	for(int i=0; i<nums.size(); i++) {
       		csum += nums[i];
            int r_sum = csum - k;    // remaining sum
       		count += mp[r_sum];
       		mp[csum]++;
       	}
        return count;
    }
};



int main() {
	Solution2 S;
	cout<<S.subarraySum({1,2,3},3)<<endl;
	cout<<S.subarraySum({1,1,1},2)<<endl;
	return 0;
}