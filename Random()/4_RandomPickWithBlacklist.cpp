// 4_RandomPickWithBlacklist.cpp
// Question - https://leetcode.com/problems/random-pick-with-blacklist/
// Code - https://ide.codingblocks.com/s/649958
// Resource - https://www.youtube.com/watch?v=6LN4uD346FQ&t=773s
#include <bits/stdc++.h>
using namespace std;

// Approach - using rand(), set and hmap
// In this problem, we just randomize top N-Blacklist Elements,
// and if we find any blacklsit el while randomizing, 
// we just map it with the lower half [non-black el]

// TC - O(1)
// SC - O(B)
class Solution {
    map<int,int> mp;   	// to store the mapping of top blaclist -> bottom non-blacklist
    int top; 			// to store the size of the actual nums to be randomized!
    set<int> s; 		// to get if the number is blacklist or not
public:
    Solution(int n, vector<int>& blacklist) {
        srand(time(0));
        for(auto el: blacklist) s.insert(el);
        top = n - blacklist.size();
        n--;
        for(int i=0; i<blacklist.size(); i++) {
            if(blacklist[i] < top ) {
                // we need to make mapping
                while(s.find(n) != s.end()) n--;
                mp[blacklist[i]] = n;
                n--;
            }
        }
        
    }
    
    int pick() {
        int rn = rand()%top;
        return s.find(rn) == s.end() ? rn : mp[rn];
    }
};
