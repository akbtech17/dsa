// 5_DecodeWays2_Recursion.cpp
// 4_DecodeWays_Recursion.cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007


class Solution {
public:
    ll numDecodings(string s) {
        vector<ll> dp(s.size()+1,0);
        dp[0] = 1;

        for(ll i=1;i<=s.size();i++) {
        	// for single char
            if(s[i-1] != '0') {
            	if(s[i-1] == '*') dp[i] += (9*dp[i-1]);
            	else dp[i] += dp[i-1];
            }
            // for pair of char
            if(i != 1 and s[i-2] !='0') {
            	if(s[i-2] != '*' and s[i-1] != '*') {
            		if(stoi(s.substr(i-2,2)) <=26) dp[i] += dp[i-2];
            	}
            	else if(s[i-2] == '*' and s[i-1] != '*') {
            		if(s[i-1] <= '6') dp[i] += (dp[i-2]*2);
            		else dp[i] += dp[i-2];
            	}
            	else if(s[i-2] != '*' and s[i-1] == '*') {
            		if(s[i-2] < '2') dp[i] += (dp[i-2]*9);
            		else if(s[i-2] == '2') dp[i] +=  (dp[i-2]*6);
            	}
            	else {
            		dp[i] += (15*dp[i-2]);
            	}  
                dp[i] = (dp[i]%MOD);
            }
        }
        return dp[s.size()];
    }
};

int32_t main() {
	Solution S;
    // cout<<S.numDecodings("06")<<endl;
    // cout<<S.numDecodings("226")<<endl;
    // cout<<S.numDecodings("0")<<endl;
    cout<<S.numDecodings("1*")<<endl;
    cout<<S.numDecodings("*")<<endl;
	cout<<S.numDecodings("2*")<<endl;

    return 0;
}