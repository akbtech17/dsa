// 13_FindKPairsWithSmallestSums_MaxPQ.cpp
// Problem Link - 
// Code Link - 
// Reference Link - 

#include<bits/stdc++.h>
using namespace std;

// A1
// TC : 
// SC : 
class Solution1 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                int sum = nums1[i]+nums2[j];
                pq.push({sum,{nums1[i],nums2[j]}});
            }
        }
        while(k-- and !pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};


// A2
// TC : 
// SC : 
class Solution2 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> ans;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                int sum = nums1[i]+nums2[j];
                if(pq.size() < k) {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else {
                    if(sum<pq.top().first) {
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else break;
                }
            }
        }
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};