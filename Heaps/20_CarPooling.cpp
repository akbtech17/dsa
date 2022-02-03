// 20_CarPooling.cpp
// https://leetcode.com/problems/car-pooling/
// https://ide.codingblocks.com/s/639232

// TC - O(NLogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class mycomp {
public:
	bool operator()(pair<int,pair<int,int>> &p1, pair<int,pair<int,int>> &p2) {
		return p1.first > p2.first;
	}
};

class Solution {
public:
	bool static stc(vector<int> &v1, vector<int> &v2) {
		return v1[1] < v2[1];
	}
    bool carPooling(vector<vector<int>>& trips, int capacity) {
  		// sort the trips wrt to starting time
  		sort(trips.begin(),trips.end(),stc);
  		// et : st : cap
  		priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, mycomp> pq;
  		for(auto trip : trips) {
  			int cst = trip[1], cet = trip[2], ccap = trip[0]; 
  			while(!pq.empty() and pq.top().first <= cst) {
  				capacity += pq.top().second.second;
  				pq.pop();
  			}

  			if(ccap <= capacity) {
  				capacity -= ccap;
  				pq.push({cet,{cst,ccap}});
  			}
  			else return false;
  		}
  		return true;      
    }
};