// 9_TopKFrequentElements.cpp
// https://leetcode.com/problems/top-k-frequent-elements/
// https://ide.codingblocks.com/s/635546

// TC - O(NlogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   		unordered_map<int,int> mp;
   		for(auto el : nums) mp[el]++;

   		priority_queue<pair<int,int>> pq;
   		for(auto p : mp) pq.push({p.second,p.first});
   		
   		vector<int> ans;
   		while(!pq.empty() and k--) {
   			ans.push_back(pq.top().second);
   			pq.pop();
   		}
   		return ans;
    }
};