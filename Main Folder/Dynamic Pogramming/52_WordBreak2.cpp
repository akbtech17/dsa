// 52_WordBreak2.cpp
// https://leetcode.com/problems/word-break-ii/
// https://www.youtube.com/watch?v=2NaaM_z_Jig&t=1627s
// https://ide.codingblocks.com/s/642852
#include <bits/stdc++.h>
using namespace std;

// Approach - Bottom Up DP (Accepted)
// TC - O(N*S) where N = str.size() and S = len of the largest string
// SC - O(N*S)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>({}));
        map<string,int> mp;
        for(auto wrd : wordDict) mp[wrd] = 1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                string suffix = s.substr(j,i-j+1);
                if(mp.count(suffix)>0) {
                    if(j-1<0) {
                        dp[i].push_back(suffix);
                    }
                    else if(j-1>=0) {
                        for(auto ss : dp[j-1]) {
                            dp[i].push_back(ss+" "+suffix);
                        }
                    }
                }
            }
        }
        for(auto str: dp[n-1]) cout<<str<<endl;
        cout<<endl;
        return dp[n-1];
    }
};


int main() {
	Solution S;
	S.wordBreak("catsanddog",{"cat","cats","and","sand","dog"});
	S.wordBreak("pineapplepenapple",{"apple","pen","applepen","pine","pineapple"});
	S.wordBreak("catsandog",{"cat","cats","and","sand","dog"});

	return 0;
}