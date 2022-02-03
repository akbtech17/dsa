// 2_CountVowelSubstringsOfAString.cpp
// https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// https://ide.codingblocks.com/s/642423
#include <bits/stdc++.h>
using namespace std;

// Approach - Bruteforce + MAP
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int countVowelSubstrings(string word) {
        int ans = 0;
        int cnt = 0;
        map<char,int> mp;
        mp['a']++;
        mp['e']++;
        mp['o']++;
        mp['u']++;
        mp['i']++;
        int s = 0;
        int e = 0;
       int n = word.size();
       for(int i=0; i<n; i++) {
           for(int j=i; j<n; j++) {
               map<char,int> mp2;
               for(int k=i; k<=j; k++) {
                   mp2[word[k]]++;
               }
               bool flag = false;
               for(auto p : mp) {
                   if(mp2.count(p.first) == 0 or mp.size() != mp2.size()) {
                       flag = 1;
                       break;
                   }
               }
                if(!flag) ans++;

           }
       }
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.countVowelSubstrings("aeiouu")<<endl;
	cout<<S.countVowelSubstrings("cuaieuouac")<<endl;
	cout<<S.countVowelSubstrings("bbaeixoubb")<<endl;

	return 0;
}