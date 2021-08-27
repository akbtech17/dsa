// 1_QueriesOnCircle_Basic.cpp
// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findEd(vector<int> p1, vector<int> p2) {
    	int x = p1[0]-p2[0];
    	int y = p1[1]-p2[1];
    	int d = (x*x)+(y*y);
    	return d;
    }
    static bool myComp(int d1, int d2) {
    	return d1>d2;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> vec;
        for(auto q : queries) {
            int ans = 0;
            vector<int> ed;
            int r = q[2];
            r *= r;
            for(auto p : points) {
                ed.push_back(findEd(q,p));
            }
            sort(ed.begin(),ed.end(),myComp);
            int i=0;
            while(i<ed.size() and ed[i]<r) i++;
            vec.push_back(ed.size() - i);
        }
        return vec;
    }
};