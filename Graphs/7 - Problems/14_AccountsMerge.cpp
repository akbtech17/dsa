// 4_AccountsMerge.cpp
// https://leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> parent;
	int total_comps;
public:
	DSU(int n) {
		this->parent.resize(n);
		for(int i=0; i<n; i++) parent[i] = i;
		total_comps = n;
	} 

	int get_sp(int x) {
		if(x == parent[x]) return x;
		return parent[x] = get_sp(parent[x]); // path compression...
	}

	void do_union(int x, int y) {
		int sp1 = get_sp(x);
		int sp2 = get_sp(y);

		if(sp1 != sp2) {
			parent[sp1] = sp2;
			total_comps--;
		}
		return;
	}

	int tell_nos() {
		return total_comps;
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
  		int nfa = accounts.size();
  		DSU dsu(nfa);

  		unordered_map<string, int> mp;
  		for(int i=0; i<nfa; i++) {
  			for(int j=1; j<accounts[i].size(); j++) {
  				// if not found
  				if(mp.count(accounts[i][j]) == 0) {
  					mp[accounts[i][j]] = i;
  				} 
  				else {
  					dsu.do_union(i,mp[accounts[i][j]]);
  				}
  			}
  		}

  		// get number of merged accounts...
  		int n = dsu.tell_nos();
  		vector<vector<string>> ans(n);
  		unordered_map<int,int> gid2outputIdx;
  		int nextIdx = 0;
  		
  		for(auto p: mp) {
  			string email = p.first;
  			int sp = dsu.get_sp(p.second);

  			if(gid2outputIdx.count(sp) == 0) {
  				gid2outputIdx[sp] = nextIdx;
  				string name = accounts[sp][0];
  				ans[nextIdx].push_back(name);
  				ans[nextIdx].push_back(email);
  				nextIdx;
  			}
  			else {
  				ans[gid2outputIdx[sp]].push_back(email);
  			}
  		}

  		for(auto v: ans) {
  			sort(v.begin()+1,v.end());
  		}

  		return ans;
    }
};

int main() {
	Solution S;
	S.accountsMerge({
		{"John","johnsmith@mail.com","john_newyork@mail.com"},
		{"John","johnsmith@mail.com","john00@mail.com"},
		{"Mary","mary@mail.com"},
		{"John","johnnybravo@mail.com"}
	});

	return 0;
}

