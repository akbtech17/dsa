// 25_HIndex2.cpp
// Problem Link - https://leetcode.com/problems/h-index-ii/
// Code Link - https://ide.codingblocks.com/s/669112
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// TC: O(NLogN) 
// SC: O(1)
class Solution {
public:
    bool isCondTrue(vector<int>& citations, int h) {
        int n = 0;
        for(auto el: citations) if(el>=h) n++;
        return n>=h;
    } 
    int hIndex(vector<int>& citations) {
        // sort(citations.begin(),citations.end());
        int s = 0, e = citations[citations.size()-1];
        
        int ans = -1;
        while(s<=e) {
            int m = s+(e-s)/2;
            if(isCondTrue(citations, m)) {
                // maximize
                ans = m;
                s = m+1;
            }
            else {
                // reduce
                e = m-1;
            }
        }
        
        return ans;
    }
};