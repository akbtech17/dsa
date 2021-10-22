// 11_SortCharByFrequency.cpp
// https://leetcode.com/problems/sort-characters-by-frequency/
// https://ide.codingblocks.com/s/639229

// TC - O(NLogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string str) {
        map<char,int> mp;
        for(auto ch : str) mp[ch]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto p : mp) pq.push({p.second,p.first});
        
        string ans = "";
        while(!pq.empty()) {
            int fre = pq.top().first;
            char ch = pq.top().second;
            
            while(fre--) {
                ans += ch;    
            }
            pq.pop();
        }
        
        return ans;
    }
};