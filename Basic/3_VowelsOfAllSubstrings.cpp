// 3_VowelsOfAllSubstrings.cpp
// https://leetcode.com/problems/vowels-of-all-substrings/
// https://ide.codingblocks.com/s/642425
#include <bits/stdc++.h>
using namespace std;

// Approach - Bruteforce + Vector
// TC - O(N)
// SC - O(N)
class Solution {
public:
    long long countVowels(string word) {
        long long int ans = 0;
        int n = word.size();
        
        map<char,long long int> mp;
        mp['a']++;        
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;

        vector<long long int> v;
        for(int i=0; i<n; i++) {
            if(i == 0) v.push_back(n);
            else {
                long long int right = n-i;
                long long int left = v[i-1]-i;
                v.push_back(left+right);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(mp.count(word[i]) > 0) ans += v[i];
        }
        
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.countVowels("aba")<<endl;
	cout<<S.countVowels("abc")<<endl;
	cout<<S.countVowels("noosabasboosa")<<endl;

	return 0;
}