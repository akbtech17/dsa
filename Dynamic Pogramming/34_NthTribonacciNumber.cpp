// 34_NthTribonacciNumber.cpp
// Problem Link - https://leetcode.com/problems/n-th-tribonacci-number/
// Solution Link - https://ide.codingblocks.com/s/636311

#include <bits/stdc++.h>
using namespace std;

// Approach : Three vairables
// TC : O(N)
// SC : O(1)
class Solution {
public:
    int tribonacci(int n) {
        if(n <=1) return n;
        if(n==2) return 1;
        int a = 0, b = 1, c = 1, ans;
        for(int i=3; i<=n; i++) {
            ans = a+b+c;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};