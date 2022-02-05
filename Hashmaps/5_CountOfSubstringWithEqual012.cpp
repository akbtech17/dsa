// 5_CountOfSubstringWithEqual012.cpp
// Question Link - https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1
// Solution Link - https://ide.codingblocks.com/s/654315
// Resource - https://www.youtube.com/watch?v=fPR4C822JOM
#include <bits/stdc++.h>
using namespace std;

// Approach: Using HMap
//           we store key <c1-c0,c2-c1>
//           if we found the same key, we know that till that point
//           means that, growth/dec in 1 and 0 is same, and 1 and 2 is same
//           ie 0,1,2 no is same
//           
// TC: O(N)
// SC: O(N)
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        long long ans = 0;
        map<pair<long long, long long>,long long> mp;
        mp[{0,0}] = 1;
        long long cnt[3] = {0};
        for(long long i=0; i<str.size(); i++) {
            long long cno = str[i]-'0';
            cnt[cno]++;
            pair<long long,long long> key({cnt[1]-cnt[0], cnt[2]-cnt[1]});
            if(mp.count(key) != 0) {
                ans += mp[key];
            }
            mp[key]++;
        }
        return ans;
    }
};