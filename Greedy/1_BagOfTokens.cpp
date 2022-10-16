// 1_BagOfTokens.cpp
// Problem Link - https://leetcode.com/problems/bag-of-tokens/
// Solution Link - https://ide.codingblocks.com/s/673714

#include <bits/stdc++.h>
using namespace std;

// Approach : Two Pointers
// TC : O(NLogN)
// SC : O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int s = 0, e = tokens.size()-1;
        int score = 0;
        while(s<=e) {
            bool moved = false;
            if(power>=tokens[s]) {
                power -= tokens[s++];
                score++;
                moved = true;
            }
            else {
                if(s == e) break;
                if(score >= 1) {
                    score--;
                    power += tokens[e--]; 
                    moved = true;
                }
            }
            if(!moved) break;
        }
        return score;
    }
};

int main() {}