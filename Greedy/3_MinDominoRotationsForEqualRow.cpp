// 3_MinDominoRotationsForEqualRow.cpp
// Problem Link - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// Code Link -
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> cntA(7), cntB(7), same(7);
        for(int i=0; i<A.size(); i++) {
            cntA[A[i]]++;
            cntB[B[i]]++;
            if(A[i] == B[i]) same[A[i]]++;
        }
        
        for(int i=1; i<7; i++) {
            int total = cntA[i] + cntB[i] - same[i];
            if(total == A.size()) 
                return A.size() - max(cntA[i],cntB[i]);
        }
        
        return -1;
    }
};