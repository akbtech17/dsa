// 1_CountPlaindromicSubstrings.cpp
// https://leetcode.com/problems/palindromic-substrings/
// https://youtu.be/XmSOWnL6T_I


// TC - N^2
// SC - N^2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
    	int ans = 0;
    	int n = s.size();

    	// row idx will mark the startnig idx of the substring
    	// col idx will mark the ending idx of the substring
    	vector<vector<bool>> dp(n, vector<bool>(n,false));

    	// traversing diagonals
    	int i=0;
    	int j=0;
    	for(int d=0; d<n; d++) {
    		int i=0;
    		int j=d;
    		while(i<n and j<n) {
    			if(d == 0) {
    				dp[i][j] = true;
    				ans++;
    			}
    			else if(d == 1) {
    				if(s[i] == s[j]) {
    					dp[i][j] = true;
    					ans++;
    				}
    			}
    			else {
    				// suppose we have string [i..j]
    				// if [i+1]...[j-1] is pal
    				// and s[i] == s[j] then true
    				if(dp[i+1][j-1] == true and s[i] == s[j]) {
    					dp[i][j] = true;
    					ans++;
    				}
    			}
    			i++,j++;
    		}
    	}
    	return ans;        
    }
};

int main() {
	Solution S;
	cout<<S.countSubstrings("abccbc")<<endl;
	cout<<S.countSubstrings("abc")<<endl;
	cout<<S.countSubstrings("aaa")<<endl;

	return 0;
}