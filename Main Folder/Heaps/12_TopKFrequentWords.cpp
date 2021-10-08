// 12_TopKFrequentWords.cpp
// https://leetcode.com/problems/top-k-frequent-words/


// TC - O()
// SC - O()
#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(pair<int,string> p1,pair<int,string> p2) {
        if(p1.first == p2.first) {
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto word : words) {
            mp[word]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, comp> pq;
        for(auto p : mp) {
            pq.push({p.second,p.first});
        }
        
        vector<string> ans;
        while(!pq.empty() and k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

