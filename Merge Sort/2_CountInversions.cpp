// 2_CountInversions.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1 
// Code Link - https://ide.codingblocks.com/s/668841
// Resource - https://www.youtube.com/watch?v=8ySvTntD2eY&t=499s&ab_channel=AyushiSharma
#include <bits/stdc++.h>
using namespace std;

// Approach: Merge Sort (Divide and Conquer)
// TC: O(NLogN)
// SC: O(N)
class Solution {
    long long int ans;
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long int s, long long int m, long long int e) {
        long long int i = s, j = m+1;
        vector<long long int> temp;
        
        while(i<=m and j<=e) {
            if(arr[i]<=arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                // add inversions
                // cout<<arr[i]<<" "<<arr[j]<<" "<<(m-i)+1<<endl;
                ans += (m-i)+1;
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=m) {
            temp.push_back(arr[i++]);
        }
        while(j<=e) {
            temp.push_back(arr[j++]);
        }
        
        j = 0 ;
        for(i=s; i<=e; i++) arr[i] = temp[j++];
        return;
    }
    void mergeSort(long long arr[], long long int s, long long int e) {
        if(s == e or s>e) return;
        
        long long int m = s+(e-s)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr,s,m,e);
        
        return;
    }
    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here
        ans = 0;
        mergeSort(arr, 0, N-1);
        // cout<<"\nsorted array ";
        // for(long long int i=0; i<N; i++) cout<<arr[i]<<" ";
        return ans;
    }

};