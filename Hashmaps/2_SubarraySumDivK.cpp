// 2_subarraySumDivK.cpp
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// https://www.youtube.com/watch?v=QM0klnvTQzk&t=62s
// https://ide.codingblocks.com/s/632631

#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2)
// SC - O(n)
class Solution {
public:
    int subarraysDivByK(vector<int> nums, int k) {
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
                if(cs % k == 0) count++;
            }
        }   
        return count;
    }
};


// TC - O(n)
// SC - O(n)
// Approach - While Building CSUM

// 1. If Rem is Positive
// suppose we are standing  at jth idx
// and its sum2 = k*x+r2
// and we have some sum1 with rem r1 == r2 previously stored in map
// sum1 = k*y+r1 = k*y+r2
// Now, subarray sum would be = sum2 - sum1
//                            = k*(y-x) + (r2-r2) = k*(y-x)
//                            = multiple of k

// 2. if Rem is Negative
// try to make it positive
// suppose sum = k*x-rem
// add and substract by k
// sum = (x-1)k+(k-rem)

// matlab kabhi bhi rem negative ay, add k :) 


class Solution2 {
public:
    int subarraysDivByK(vector<int> nums, int k) {
        int count = 0;
       	unordered_map<int,int> mp;
       	mp[0] = 1;
        // store the rem 0, with freq 1
       	int csum = 0;
        // we will store rem in the map
       	for(int i=0; i<nums.size(); i++) {
       		csum += nums[i];
            int rem = csum % k;    // find rem
            // if rem neg, make it postive
            if(rem < 0) rem += k;
            count += mp[rem];
            mp[rem]++;
       	}
        return count;
    }
};



int main() {
	Solution2 S;
	cout<<S.subarraysDivByK({4,5,0,-2,-3,1},5)<<endl;
	cout<<S.subarraysDivByK({5},9)<<endl;
	return 0;
}