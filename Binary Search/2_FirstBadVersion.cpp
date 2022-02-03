// 2_FirstBadVersion.cpp
// https://leetcode.com/problems/first-bad-version/
// https://ide.codingblocks.com/s/635295

#include <bits/stdc++.h>
using namespace std;

// Approach - Iterative
// TC - O(LogN)
// SC - O(1)
#define ll long long int
class Solution {
public:
    int firstBadVersion(int n) {
        ll ans = 0;
        ll s = 1;
        ll e = n;
        
        while(s<=e) {
            ll m = (s+e)/2;
            if(isBadVersion(m) == false) s = m+1; 
            else {
                ans = m;
                e = m-1;
            }
        }
        return ans;
    }
};