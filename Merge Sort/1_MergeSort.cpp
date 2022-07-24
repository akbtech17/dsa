// 1_MergeSort.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/merge-sort/1
// Code Link - https://ide.codingblocks.com/s/668839
#include <bits/stdc++.h>
using namespace std;

// Approach: Divide and Conquer
// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
    void merge(int arr[], int l, int m, int r) {
        // Your code here
        vector<int> temp;
        int i = l, j = m+1;
        while(i<=m and j<=r) {
            if(arr[i]<=arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=m) {
            temp.push_back(arr[i++]);
        }
        while(j<=r) {
            temp.push_back(arr[j++]);
        }
        
        j = 0;
        for(i=l; i<=r; i++) arr[i] = temp[j++];
        
        return;
    }
    void mergeSort(int arr[], int l, int r) {
        // base case
        if(l == r or l>r) {
            return;
        }
        
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
        
        return;
    }
};