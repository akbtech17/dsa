// 11_SortCharByFrequency.cpp
// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

// struct comp {
//     bool operator()(int,char> p1,int,char> p2) {
//         return p1.second<p2.second;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        string ans;
        map<char,int> mp;
        for(auto el : s) {
            mp[el]++;
        }
        priority_queue<int,char>> pq;
        for(auto p : mp) {
        	pq.push({p.second,p.first});
        }
        while(!pq.empty()) {
            char ch = pq.top().first;
            int fre = pq.top().second;
            pq.pop();
            while(fre--) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};