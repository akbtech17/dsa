// 51_WordBreak.cpp
// https://leetcode.com/problems/word-break/
// https://www.youtube.com/watch?v=2NaaM_z_Jig&t=1627s
// https://ide.codingblocks.com/s/642851
#include <bits/stdc++.h>
using namespace std;

// Approach - Backtracking (TLE)
// TC - O(2^N)
// SC - O(2^N)
class Solution1 {
public:
	bool recurse(string str, unordered_map<string,int> &mp) {
		int n = str.size();
		if(n == 0) return true;
		for(int i=0; i<n; i++) {
			string prefix = str.substr(0,i+1);
			if(mp[prefix] == 1) {
				string suffix = str.substr(i+1);
				bool furtherBreakHoParaHai = recurse(suffix,mp);
				if(furtherBreakHoParaHai) return true;
			}
		}
		return false;
	}
    bool wordBreak(string str, vector<string> wordDict) {
        unordered_map<string,int> mp;
        for(string word: wordDict) mp[word] = 1;

        return recurse(str,mp);
    }
};


// Approach - Bottom Up DP (Accepted)
// TC - O(N*S) where N = str.size() and S = len of the largest string
// SC - O(N*S)
class Solution2 {
public:
    bool wordBreak(string str, vector<string> wordDict) {
        int n = str.size();
        vector<bool> dp(n, false);
       
        map<string,int> mp;
        for(auto wrd : wordDict) mp[wrd]++;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                string suffix = str.substr(j,i-j+1);
                if(mp.count(suffix)>0) {
                    if(j-1<0 or (j-1>=0 and dp[j-1])) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n-1]; 
    }
};


int main() {
	Solution1 S1;
	cout<<S1.wordBreak("leetcode",{"leet","code"})<<endl;
	cout<<S1.wordBreak("applepenapple",{"apple","pen"})<<endl;
	cout<<S1.wordBreak("catsandog",{"cats","dog","sand","and","cat"})<<endl;


	Solution2 S2;
	cout<<S2.wordBreak("leetcode",{"leet","code"})<<endl;
	cout<<S2.wordBreak("applepenapple",{"apple","pen"})<<endl;
	cout<<S2.wordBreak("catsandog",{"cats","dog","sand","and","cat"})<<endl;

	return 0;
}