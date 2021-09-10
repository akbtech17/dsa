// 18_DijointSetUnionFindAlgorithm.cpp

// Basic Points - 
// All vertices are init treated as V sets

// These 2 queries happen in O(N) time
// Union - now we can connect components in the V sets, 
//         merge two components.
// Find - how many connected componets are there ?.

// How to Implepent
// We will have two arrays,
// ans init each Vertex Set's Super Parent as Itself.

// 1 - Parents Array 1 2 3 4 5 6  
// 2 - Sets Array    1 2 3 4 5 6 

// Union Operation - 
// 1 - find superparent of x = sp1
// 2 - find superparent of y = sp2
// 3 - update parent of [sp1] = sp2


// So in general we are building a Directed Graph
// in which each child is pointing to its parent, and 
// every node is having exactly one superparent


// Time Complexcity Analysis
// to Unite the 2 components
// when we use get() - returns the superparent of the componenet
// get() will take O(Vertices) time
// and when we call get() for N queries, TC => O(V*N)



// Optimization - using Path Compression

// Trivial Function - TC N, SC N
// int get(int x) {
// 	if(x == par[x]) return par[x];
// 	return get(par[x]);
// }

// Path Compression - 
// we aim to connect all its children directly to 
// the super parent


// TC - O(1) , as it is always compressing the path (only two steps)
// int get(int x) {
// 	if(x == par[x]) return par[x];
// 	return par[x] = get(par[x]);               <- path compression
// }

#include <bits/stdc++.h>
using namespace std;

class dsu {
	vector<int> par;
	int total_comps;

public:
	// initialization of parents
	dsu(int n) {
		this->par.resize(n);
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
			par[sp1] = sp2;        // merging x in y, as x's SP is now y's SP
			total_comps--;         // every time we do union, 1 comp --
		}
	}

	// Query 2 - getConnected Components
	int tell_CC() {
		return total_comps;
	}

};

int main() {

}