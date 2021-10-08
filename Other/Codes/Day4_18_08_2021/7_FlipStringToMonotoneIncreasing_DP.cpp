// 7_FlipStringToMonotoneIncreasing_DP.cpp
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <bits/stdc++.h>
#define vi vector<int> 
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string str) {
        int n = str.size();
        vi dp(n+1,0);
        dp[0] = 0;
        int oneCount = 0;

        for(int i=1; i<=n; i++) {
        	char ch = str[i-1];
        	if(ch == '0') {
        		// case1 : we have to keep 0
        		// we need to remove all 1 before ith pos, ie oneCount

        		// case2 : remove curr 0,
        		// flips(i-1) + 1

        		dp[i] = min(dp[i-1]+1,oneCount);
        	}
        	else {
        		// since it is always valid to append 1
        		// to a valid string
        		dp[i] = dp[i-1];
        		oneCount++;
        	}	

        }

        return dp[n];
    }
};

int main() {
	Solution S;
	cout<<S.minFlipsMonoIncr("00110")<<endl;
	cout<<S.minFlipsMonoIncr("010110")<<endl;
	cout<<S.minFlipsMonoIncr("00011000")<<endl;

	return 0;
}