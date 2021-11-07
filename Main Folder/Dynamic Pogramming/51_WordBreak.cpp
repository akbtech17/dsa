// 51_WordBreak.cpp
// https://leetcode.com/problems/word-break/
#include <bits/stdc++.h>
using namespace std;

// Approach - Backtracking
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
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(string word: wordDict) mp[word] = 1;

        return recurse(str,mp);
    }
};


// Approach2 - Backtracking + Memoization (TopDown DP)
// TC - O(2^N)
// SC - O(2^N)
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//         vector<int> memo(s.size(), -1);
//         return check(s, wordSet, 0, memo);
//     }
//     bool check(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
//         if (start >= s.size()) 
//             return true;
//         if (memo[start] != -1) 
//             return memo[start];
//         for (int i = start + 1; i <= s.size(); ++i) {
//             if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo)) {
//                 memo[start] = 1;
//                 return memo[start];
//             }
//         }
//         memo[start] = 0;
//         return memo[start];
//     }
// };
class Solution2 {
public:
	int recurse(string str, unordered_map<string,int> &mp, vector<int> &dp,int start = 0) {
		int n = str.size();
		if(n == 0) return dp[start] = 1;
		if(dp[start] != -1) return dp[start];

		for(int i=0; i<n; i++) {
			string prefix = str.substr(0,i+1);
			if(mp[prefix] == 1) {
				string suffix = str.substr(i+1);
				bool furtherBreakHoParaHai = recurse(suffix,mp,dp,i+1);
				if(furtherBreakHoParaHai) return dp[start] = 1;
			}
		}
		return dp[start] = 0;
	}
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(string word: wordDict) mp[word] = 1;
        vector<int> dp(str.size()+1,-1);
        return recurse(str,mp,dp) == 0 ? false : true;
    }
};

int main() {

}