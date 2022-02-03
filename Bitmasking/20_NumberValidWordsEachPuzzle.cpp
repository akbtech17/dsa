// 20_NumberValidWordsEachPuzzle.cpp
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
// https://www.youtube.com/watch?v=9jV0CC_C26s&t=1600s
// https://ide.codingblocks.com/s/642855
#include <bits/stdc++.h>
using namespace std;

// Approach - We will make bitMap of each words and puzzles, and take & to see if it satisfies the condition or not.
// TC - O(MN) where M = words, N = puzzles
// SC - O(M) 
class Solution {
public:
    int makeMask(string &word) {
        int mask = 0;
        for(char ch: word) {
            int pos = ch-'a';
            mask = mask|(1<<pos);
        }
        return mask;
    }
    vector<int> findNumOfValidWords(vector<string> words, vector<string> puzzles) {
        unordered_map<char,vector<int>> mp;
        
        for(char ch = 'a'; ch <= 'z'; ch++) {
            mp[ch] = vector<int>({});
        }
        
        for(auto word: words) {
            int msk = makeMask(word);
            for(int i=0; i<26; i++) {
                if((msk&(1<<i)) != 0) mp['a'+i].push_back(msk);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<puzzles.size(); i++) {
            int cans = 0;
            vector<int> cwords = mp[puzzles[i][0]];
            int pmask = makeMask(puzzles[i]);
            for(auto msk : cwords) {
                if((pmask&msk) == msk) cans++;
            }
            ans.push_back(cans);
        }

        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
        return ans;
    }
};

int main() {
	Solution S;
	S.findNumOfValidWords({"aaaa","asas","able","ability","actt","actor","access"},{"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"});
	S.findNumOfValidWords({"apple","pleas","please"},{"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"});

	return 0;
}