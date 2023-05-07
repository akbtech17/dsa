// 2_FirstNegativeNumberK.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// Solution Link - https://ide.codingblocks.com/s/685127

// TC: O(N)
// SC: O(K)
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    // maintain 2 pointer s, e
    int s = 0, e = 0;
    
    vector<long long> ans;
    queue<int> q;
    
    // run look till e < n
    while(e < N) {
        // add calc for first el in window : as we maintain min 1 el in every window
        if(A[e] < 0) q.push(A[e]);
        
        // find the wlen 
        int wlen = e-s+1;  // min 1 in every case
        if(wlen < K) {
            e++;
        }
        else if(wlen == K) {
            // grab the ans for curr window
            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);
            
            // remove the calc for s'th el
            if(!q.empty() and q.front() == A[s]) q.pop();
            
            // slide
            s++; e++;
        }
    }
    return ans;
}