// 5_FindAllAnagramsInString.cpp
// Problem - https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Code - https://ide.codingblocks.com/s/653872
#include <bits/stdc++.h>
using namespace std;

// Appraoch - Sliding Window using 2 Pointer Approach
// TC: O(N)
// SC: O(N)
class Solution {
public:
    vector<int> findAnagrams(string str, string p) {
        vector<int> ans;
        if(str.size() < p.size()) return ans;
        
        unordered_map<char,int> pmp, smp;
        for(auto ch: p) pmp[ch]++;
        
        int ch_req = p.size();    
        
        int s = 0, e = -1;
        int n = str.size();
        
        while(e<n) {
            int ws = e-s+1;

            // expand the window
            if(ws < p.size()) {
                // add el 
                char ch = str[e+1];
                if(smp[ch] < pmp[ch]) ch_req--;
                smp[ch]++;
                e++;
            }
            // maintain the window, and slide it
            if(ws == p.size()) {
                if(ch_req == 0) {
                    ans.push_back(s);
                }
                // remove the starting char
                char ch = str[s];
                if(smp[ch] <= pmp[ch]) ch_req++;
                smp[ch]--;
                // move window
                s++;
            }
        }
        return ans;
    }
};
