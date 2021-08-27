// 3_GroupPeople_HashMap.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
  		map<int,vector<int>> mp;
  		vector<vector<int>> ans;

  		for(int i=0; i<groupSizes.size(); i++) {
  			int cgs = groupSizes[i];
  			if(mp.count(cgs) > 0) {
  				if(mp[cgs].size() < cgs) mp[cgs].push_back(i);
  				else {
  					ans.push_back(mp[cgs]);
  					mp.erase(cgs);
  					mp[cgs].push_back(i);
  				}
  			}
  			else {
  				mp[cgs].push_back(i);
  			}
  		}
  		for(auto p : mp) {
  			if(p.second.size()!=0) ans.push_back(p.second);
  		}
  		return ans;
    }
};