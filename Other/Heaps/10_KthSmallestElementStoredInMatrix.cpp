// 10_KthSmallestElementStoredInMatrix.cpp
typedef pair<int,pair<int,int>> customPair;

class Solution {
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
            if(k == 0) return curr.first;
            int ii = curr.second.first;
            int jj = curr.second.second;
            if(jj+1 < n) pq.push({matrix[ii][jj+1],{ii,jj+1}});
        }
        return matrix[n-1][n-1];
    }
};