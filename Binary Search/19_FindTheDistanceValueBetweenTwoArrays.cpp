// 19_FindTheDistanceValueBetweenTwoArrays.cpp
// Problem Link - https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Code Link - 
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        
        for(int i=0; i<arr1.size(); i++) {
            bool flag = false;
            for(int j=0; j<arr2.size(); j++) {
                int t = abs(arr1[i]-arr2[j]);
                if(t<=d) {
                    flag = true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        
        return ans;
    }
};