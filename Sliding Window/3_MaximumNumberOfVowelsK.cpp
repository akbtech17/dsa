// 3_MaximumNumberOfVowelsK.cpp
// Problem Link - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Solution Link - https://ide.codingblocks.com/s/685128

// TC: O(N)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        if(
            ch == 'a' or 
            ch == 'e' or 
            ch == 'i' or 
            ch == 'o' or 
            ch == 'u') return true;
        return false;
    } 
    int maxVowels(string str, int k) {
        int s = 0, e = 0;
        int n = str.size();

        int maxCount = 0;
        int currVowelCount = 0;

        while(e < n) {
            if(isVowel(str[e])) currVowelCount += 1;
            int wlen = e - s + 1;
            if(wlen < k) e++;  
            else {
                maxCount = max(maxCount, currVowelCount);
                if(isVowel(str[s])) currVowelCount -= 1;
                s++, e++;
            }
        }
        return maxCount;
    }
};