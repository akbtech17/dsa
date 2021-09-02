// 19_DSU_PairingProblem.cpp
// https://hack.codingblocks.com/app/practice/1/627/problem

// There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
// You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
// Find out the number of ways in which cities can be chosen.

// Input Format
// The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

// Constraints
// 1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

// Sample Input
// 5 3
// 0 1
// 2 3
// 0 4

// Sample Output
// 6

// Explanation
// 0 1 4 cannot be reached by 2 
// hence (2,0) (2,1) (2,4) and also 0 1 4 
// cannot be reached by 3 so (3,0) (3,1) (3,4) hence 6 ways.


// Solution
// 1 - Use Trivial DSU
// 2 - we need to keep track of number of vertices in each component
// to do so we will need another array, size[]
// storing size of component wrt to SuperParents

#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> par;
	vector<int> siz;
	int total_comps;

public:
	// initialization of parents
	DSU(int n) {
		this->par.resize(n);
		this->siz.resize(n,1);
		for(int i=0; i<n; i++) par[i] = i;

		total_comps = n;
	}
	// funciton to return the super parent, tc const
	int get_sp(int x) {
		if(x == par[x]) return x;
		return par[x] = get_sp(par[x]);  // path compression here...
	}
	// Query 1 - UNION
	void do_union(int x, int y) {
		int sp1 = get_sp(x);
		int sp2 = get_sp(y);
		if(sp1 != sp2) {           // check if they are not already connected
			par[sp1] = sp2;
			
			// as we are always merging x comp into y 
			// size of y SP will become x+y
			// size of x SP will become 0
			siz[sp2] += siz[sp1];
			siz[sp1] = 0;
			
			total_comps--;         // every time we do union, 1 comp --
		}

		
	}

	// Query 2 - getConnected Components
	int tell_CC() {
		return total_comps;
	}

	int get_size(int sp) {
		return siz[sp];
	}
	
};

int main() {
	int V,E;
	cin>>V>>E;

	DSU obj(V);
	for(int i=0; i<E; i++) {
		int x,y;
		cin>>x>>y;
		obj.do_union(x,y);
	}

	// now for each city
	// we have to connect all cities which are 
	// not connected with our current city
	// by raods, 
	// after adding all these roads, their will be duplicate roads
	// 0 - 1 and 1 - 0 is considered one
	// to avoid this, we have to divide the ans by 2.

	int ans = 0;
	for(int i=0; i<V; i++) {
		// if ith vertex is considered as curr city
		int sp_of_curr_city = obj.get_sp(i);
		int el_not_in_curr_city = V-obj.get_size(sp_of_curr_city);
		ans += el_not_in_curr_city;
	}
	cout<<ans/2;
	return 0;
}