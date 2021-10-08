// 6-BadVersion.cpp
// https://leetcode.com/problems/first-bad-version/submissions/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    ll helper(ll s, ll e, ll ans) {
        if(s>e) {
            return ans;
        }
        ll mid = (s+e)/2;
        bool ib = isBadVersion(mid);
        if(ib) {
            ans = mid;
            return helper(s,mid-1,ans);
        }
        return helper(mid+1,e,ans);
    }
    int firstBadVersion(int n) {
        return (int)helper(1,n,-1);
    }
};

int main() {
	
}