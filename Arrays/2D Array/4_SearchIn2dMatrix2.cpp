// 4_SearchIn2dMatrix2.cpp
// Problem Link - https://leetcode.com/problems/search-a-2d-matrix-ii/
// Code Link - https://ide.codingblocks.com/s/668838
#include <bits/stdc++.h>
using namespace std;

// Approach: Two Pointers
// TC: O(N+M)
// SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int key) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0, j=n-1;
        while(i<m and j>=0) {
            if(matrix[i][j] == key) return true;
            else if(key>matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};