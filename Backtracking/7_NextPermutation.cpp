// 7_NextPermutation.cpp
// Question - https://leetcode.com/problems/next-permutation/
// Code - 
// Resource - https://www.youtube.com/watch?v=LuLCLgMElus&t=239s
#include <bits/stdc++.h>
using namespace std;

// A1: Inbuilt Function (Inplace) (Accepted)
// TC - O(N)
// SC - O(1)
// Comparisons - N/2
// Return Value - true(if next lexi-greater order is possible)/false(if not)
class Solution1 {
    vector<vector<int>> allPermutations;
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }
};

// A2: Generate all possible permutations! (TLE)
//     0- Use strings, to easily sort in lexi order.
//     1- Use backtracking to generate all possible permutations,
//        ans use set to store only the unique once
//     2- Grab the next permutation, wholla!
// TC - O(N! + NlogN) 
// SC - O(N)
class Solution2 {
    set<string> unique_perm;
public:
    void recurse(string &str, int i=0) {
        int n = str.size();
        if(i == n) {
            unique_perm.insert(str);
            return;
        }
        for(int j=i; j<n; j++) {
            swap(str[i],str[j]);            
            recurse(str,i+1);
            swap(str[i],str[j]);
        }
        return;
    }
    vector<int> str_to_vec(string &str) {
        vector<int> v;
        for(auto ch: str) v.push_back(ch-'0');
        return v;
    }
    void nextPermutation(vector<int>& nums) {
        string str = "";
        
        for(auto el: nums) str += char(el+'0');
        
        string temp(str);
        recurse(temp);
        
        vector<string> sorted_perm;
        for(auto el: unique_perm) sorted_perm.push_back(el);
        
        sort(sorted_perm.begin(),sorted_perm.end());
        int idx = find(sorted_perm.begin(),sorted_perm.end(),str)-sorted_perm.begin();
        if(idx == sorted_perm.size()-1) nums = str_to_vec(sorted_perm[0]);
        else nums = str_to_vec(sorted_perm[idx+1]);
    }
};


// A3: Typical Algorithm! (Most Optimal)
// TC - O(N) 
// SC - O(1)

// Intution - lies in the dictionary order, if you check the dict-order,
//            its always like this.
// suppose we have the combination 1 3 5 4 2
// it can be drawn like  5
//                     3   4
//                   1       2
// Observation - all combination will always be a increasing sequence from the backside
//               there can be atmost 1 el to N el.
// Step 1 : we need to find the breakpoint of the inc-dec sequence,
//          starting from back, we find idx k st nums[k] < nums[k+1],
//          but why from back ?
//          because it is not compulsory we will have the inc sequence from starting too. 

// Step 2 : we will find the element which is NEXT greater than nums[k],
//          we know that the second half is in dec order(or inc order from right), so starting from the right side
//          we will find the first element > nums[k], so that, ranking can be reduced.

// Step 3 : we will swap these, elements

// Step 4 : we have 1 4 5 3 2, now we know els starting from (k+1)idx are in dec order.
//          to reduce the further rank, we will make the second half
//          from dec->inc order, by reversing nums(k+1,end)

// and finally lowering rank to this extent, will get us the exact next permutation.
class Solution3 {
public:
    void nextPermutation(vector<int>& nums) {
        // Step1 : Find the breakpoint, were the inc subarray breaks.
        // Find the largest index k such that nums[k] < nums[k + 1]. 
        int n = nums.size();
        int k,l;
        
        for(k=n-2; k>=0; k--) {
            if(nums[k] < nums[k+1]) {
                break;
            }
        }
        // If no such index exists(no breakpoint or single el exists in inc sequence), 
        // arr is in dec order, highest rank
        // to get the lowest rank, 
        // just reverse nums, get them in inc order and done.
        if(k<0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        // If breakpoint exists!
        else {
            // Find the largest index l > k such that nums[k] < nums[l].
            for(l=n-1; l>k; l--) {
                if(nums[l]>nums[k]) {
                    break;
                }
            }
            // Swap nums[k] and nums[l].
            swap(nums[k],nums[l]);

            // Reverse the sub-array nums[k + 1:]
            reverse(nums.begin()+k+1,nums.end());
            return;
        }
        
        return;
    }
};

int main() {
	Solution1 S;
	vector<int> v({3,2,1});
	S.nextPermutation(v);

	for(auto el : v) cout<<el<<" ";

	return 0;
}