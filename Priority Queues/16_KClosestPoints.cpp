// 16_KClosestPoints.cpp
// https://leetcode.com/problems/k-closest-points-to-origin/
// https://ide.codingblocks.com/s/639237

// TC - O(NLogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class MyComp {
public:
    bool operator()(pair<int,vector<int>> &v1, pair<int,vector<int>> &v2) {
        return v1.first > v2.first;
    }    
};

class Solution {
public:
    int calc_dist(int x, int y) {
        return pow(x,2) + pow(y,2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, MyComp> pq;
        for(auto point : points)         
            pq.push({calc_dist(point[0],point[1]),point});
        
        vector<vector<int>> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};