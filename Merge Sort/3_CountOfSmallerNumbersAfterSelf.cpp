// 3_CountOfSmallerNumbersAfterSelf.cpp
// Problem Link - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Code Link - https://ide.codingblocks.com/s/668855
// Resource - https://www.youtube.com/watch?v=_sA1xI4XK0c&ab_channel=AyushiSharma
#include <bits/stdc++.h>
using namespace std;

// Approach: Merge Sort (Divide and Conquer)
// TC: O(NLogN)
// SC: O(N)
class Solution {
    vector<int> cnt;
public:
    void merge(vector<pair<int,int>> &arr, int s, int m, int e) {
        int i = s, j = m+1;
        vector<pair<int,int>> temp;
        
        while(i<=m and j<=e) {
            if(arr[i].first > arr[j].first) {
                cnt[arr[i].second] += e-j+1;
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=m) {
            temp.push_back(arr[i++]); 
        }
        
        while(j<=e) {
            temp.push_back(arr[j++]); 
        }
        
        j = 0;
        for(i=s; i<=e; i++) {
            arr[i] = temp[j++];
        }
        
        return;
    }
    void mergeSort(vector<pair<int,int>> &arr, int s, int e) {
        if(s==e or s>e) return;
        
        int m = s+(e-s)/2;
        mergeSort(arr,s,m);        
        mergeSort(arr,m+1,e);
        merge(arr,s,m,e);
    }
    vector<int> countSmaller(vector<int>& nums) {
        cnt = vector<int>(nums.size(),0);
        
        // create own vector of pairs of el-idx
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++) arr.push_back({nums[i],i});
        
        mergeSort(arr, 0, nums.size()-1);
        return cnt;
    }
};