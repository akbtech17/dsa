// 6_MinimumDeletionsToMakeStringBalance_DP.cpp
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

class Solution {
public:
    int minimumDeletions(string str) {
        int n = str.size();
        vi dp(n+1,0);
        dp[0] = 0;
        int bcount = 0;
        for(int i=1; i<=n; i++) {
        	char ch = str[i-1];
        	if(ch == 'a') {
        		// case1 : we have to keep a
        		// we need to remove all b before ith pos, ie bcount

        		// case2 : remove curr a,
        		// del(i-1) + 1

        		dp[i] = min(dp[i-1]+1,bcount);
        	}
        	else {
        		// since it is always valid to append b
        		// to a valid string
        		dp[i] = dp[i-1];
        		bcount++;
        	}	

        }

        return dp[n];
    }
};

int main() {
	Solution S;
	cout<<S.minimumDeletions("aababbab")<<endl;
	cout<<S.minimumDeletions("bbaaaaabb")<<endl;

	return 0;
}