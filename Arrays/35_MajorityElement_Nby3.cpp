// 35_MajorityElement_Nby3.cpp
// Problem Link - https://leetcode.com/problems/majority-element-ii/
// Code Link - 
// Resource1 - https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
// Resource2 - https://www.youtube.com/watch?v=yDbkQd9t2ig&ab_channel=takeUforward
#include <bits/stdc++.h>
using namespace std;

// A1: Bruteforce (TLE)
// TC: O(N^2)
// SC: O(1) 

// A2: Using Map 
// TC: O(N)
// SC: O(N) 


// A3: Boyer-Moore Majority Vote Algorithm
// TC: O(2N)
// SC: O(1) 
class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty()) return ans;
        
        int n = nums.size();
        
        int cnt1 = 0, cnt2 = 0;
        int cand1 = -1, cand2 = -1;
        
        for(auto el: nums) {
            if(el == cand1) cnt1++;
            else if(el == cand2) cnt2++;
            else if(cnt1 == 0) {cand1 = el; cnt1 = 1;}
            else if(cnt2 == 0) {cand2 = el; cnt2 = 1;}
            else cnt1--,cnt2--;
        }
        
        int nBy3 = n/3;
        int fe1 = 0;
        int fe2 = 0;
        
        for(auto el: nums) {
            if(el == cand1) fe1++;
            if(el == cand2) fe2++;
        }
        
        
        if(fe1 > nBy3) ans.push_back(cand1);        
        if(fe2 > nBy3 and cand1 != cand2) ans.push_back(cand2);
        
        return ans;
    }
};


int main() {
	return 0;
}