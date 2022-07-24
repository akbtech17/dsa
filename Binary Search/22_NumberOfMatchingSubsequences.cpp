// 22_NumberOfMatchingSubsequences.cpp
// Problem Link - https://leetcode.com/problems/number-of-matching-subsequences/
// Code Link - https://ide.codingblocks.com/s/668452
#include <bits/stdc++.h>
using namespace std;

// Approach: 
// - Brute force checking will time out, we need efficent way to look up words
// - Create an vector that stores indices for each character a-z in S
// - Then for each word, do a binary search for next index for current character in word 
//   that is greater than the index we last found for the alst character
// - If it doesn't exist, word doesn't exist, otherwise continue to search for word

// TC: L*(x log n)
// 	   Its time complexity is

// 	   L = dictionary size
// 	   x = size of a particular word in the dictionary
// 	   n = given string size
// 		   (suppose every word is of maximum size = 50 )
// 	   Therefore, L*(x log n) is the complexity

// 		SC: O(n)
class Solution {
public:
    int numMatchingSubseq (string str, vector<string>& words) {
		int res = 0;
        
        vector<vector<int>> mp(26); // mapping of char to idx
        for(int i=0; i<str.size(); i++) {
            mp[str[i]-'a'].push_back(i);
        }
        for(const auto word: words) {
            int idx = -1;
            bool isPresent = true;
            
            for(const auto ch: word) {
                auto it = upper_bound(mp[ch-'a'].begin(),mp[ch-'a'].end(),idx);
                if(it == mp[ch-'a'].end()) {
                    isPresent = false;
                    break;
                }
                else idx = *it;
            }
            
            if(isPresent) res++;
        }
		return res;
	}
};