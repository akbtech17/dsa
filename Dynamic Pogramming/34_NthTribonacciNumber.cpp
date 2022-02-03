// 34_NthTribonacciNumber.cpp
// https://leetcode.com/problems/n-th-tribonacci-number/
// https://ide.codingblocks.com/s/636311

// Approach - 1D BU DP
// TC - O(N)
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 or n == 1) return n;
        if(n == 2) return 1;
        
        int n1, n2, n3;
        n1 = 0;
        n2 = n3 = 1;
        
        int ans = 0;
        while(n>=3) {
            ans = n1 + n2 + n3;
            n1 = n2;
            n2 = n3;
            n3 = ans;
            
            n--;
        } 
        return ans;
    }
};