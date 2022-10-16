// 10_KthSmallestElementStoredInMatrix.cpp
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// TC - O(MN + MNLogMN)
// SC - O(MN)
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto row : matrix) 
            for(auto el : row)
                pq.push(el); 

        k -= 1;
        while(!pq.empty() and k--) pq.pop();
        return pq.empty() ? -1 : pq.top();
    }
};


typedef pair<int,pair<int,int>> customPair;
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<customPair,vector<customPair>,greater<customPair>> pq;
        int n = matrix.size();
        for(int i=0;i<n;i++) {
                pq.push({matrix[i][0],{i,0}});
            
        }  
        while(!pq.empty() and k!=0) {
            customPair curr = pq.top();
            pq.pop();
            k--;
            // cout<<curr.first<<" ";
            if(k == 0) return curr.first;
            int ii = curr.second.first;
            int jj = curr.second.second;
            if(jj+1 < n)pq.push({matrix[ii][jj+1],{ii,jj+1}});
        }
        return matrix[n-1][n-1];
    }
};