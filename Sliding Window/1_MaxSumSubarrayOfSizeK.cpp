// 1_MaxSumSubarrayOfSizeK.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
// Solution Link - https://ide.codingblocks.com/s/685126

// TC: O(N)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long msum = 0;
        long csum = 0;
        
        
        int s = 0, e = 0;
        
        
        while(e < N) {
            // add calc for first el in window : as we maintain min 1 el in every window
            csum += Arr[e];
            
            // find the wlen 
            int wlen = e - s + 1; // min 1 in every case
            if(wlen < K) e++;
            else {
                // grab the ans for curr window
                msum = max(csum, msum);
                
                // remove the calc for s'th el
                csum -= Arr[s];
                
                // slide
                s++, e++;
            }
        }
        
        return msum;
    }
};