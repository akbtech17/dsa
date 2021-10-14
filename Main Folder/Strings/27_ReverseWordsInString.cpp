// 27_ReverseWordsInString.cpp
// https://leetcode.com/problems/reverse-words-in-a-string/
// https://ide.codingblocks.com/s/635921

#include <bits/stdc++.h>
using namespace std;

// Approach1 - start iterating from start
// TC - O(N)
// SC - O(N)
class Solution1 {
public:
    string reverseWords(string str) {
        int n = str.size();
        int i=0;
        string ans = "";
        
        // remove the leading spaces
        while(i<n and str[i]==' ') i++;
        
        for(;i<n;) {
            string word = "";
            while(i<n and str[i]!=' ') word += str[i++];
            if(!ans.empty()) ans.insert(0," ");
            ans.insert(0,word);
            while(i<n and str[i]==' ') i++;
        }
        
        return ans;
    }
};

// Approach2 - start iterating from end
// TC - O(N)
// SC - O(N)
class Solution2 {
public:
    string reverseWords(string str) {
        int n = str.size();
        int i=n-1;
        string ans = "";
        
        // remove the trailing spaces
        while(i>=0 and str[i]==' ') i--;
        
        for(;i>=0;) {
        	// extract the curr word
            string word = "";
            while(i>=0 and str[i]!=' ') word += str[i--];
            // reverse the curr word
            reverse(word.begin(), word.end());
            if(!ans.empty()) ans.append(" ");
            ans.append(word);
            // skip the next spaces
            while(i>=0 and str[i]==' ') i--;
        }
        
        return ans;
    }
};


// Approach3 - Two Pointers
// TC - O(N)
// SC - O(1)

class Solution3 {
public:
    string reverseWords(string str) {
        int n = str.size();
        // remove all extra spaces from the string
        int i = 0;
        while(str[i] == ' ') i++;
        int s = 0;
        while(i<n) {
            while(i<n and str[i] != ' ') str[s++] = str[i++];
            while(i<n and str[i] == ' ') i++;
            if(i != n) str[s++] = ' ';
        }
        str = str.substr(0,s);
        
        // reverse the main string
        s = 0;
        n = str.size();
        int e = n-1;
        while(s<e) swap(str[s++],str[e--]);
        
        // reverse each word
        for(i=0; i<n;) {
            s = i;
            while(i<n and str[i]!=' ') i++;
            e = i-1;
            while(s<e) swap(str[s++],str[e--]);
            i++;   // skip the space
        }
        
        return str;
    }
};

