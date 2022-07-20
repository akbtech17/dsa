// 29_FindTheTownJudge.cpp
// Problem Link - https://leetcode.com/problems/find-the-town-judge/
// Code Link - https://ide.codingblocks.com/s/660005
// Resource Link - https://www.youtube.com/watch?v=UDbdB5zfJ6E&ab_channel=AyushiSharma
#include <bits/stdc++.h>
using namespace std;

// A1: Using Map
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through edges.
// SC: O(N) + O(N) Space for mp[to store the trusts] and cnt_of_trusts.
class Solution1 {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp, cnt_of_trust;
        
        for(auto ed: trust) {
            mp[ed[0]] = ed[1];
            cnt_of_trust[ed[1]]++;
        }
        
        for(int i=1; i<=n; i++) {
            if(mp.count(i) == 0) {
                // then it might be town judge,
                // because he doesnt trusts anyone
                
                // but wait, check if all other trusts him or not
                if(cnt_of_trust[i] == n-1) return i;
            }
        }
        
        return -1;
    }
};


// A2: Using Indegree and Outdegree Concept
// TC: O(N+E) N is the time taken for visiting N nodes and E is for traveling through edges.
// SC: O(N) + O(N) Space for indegree and outdegree array. 
class Solution2 {
public:
	// 1. Indegree of the town judge must be n-1
	// 2. Outdegree of the town judge must be 0
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0), outdegree(n+1,0);
        
        for(auto edge: trust) {
            outdegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        for(int i=1; i<=n; i++) {
            if(indegree[i] == n-1 and outdegree[i] == 0) return i; 
        }
        
        return -1;
    }
};