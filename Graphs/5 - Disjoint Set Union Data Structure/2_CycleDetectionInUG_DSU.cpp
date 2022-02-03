// 20_CycleDetectionInUG_DSU.cpp
// Time Complexcity = O(E*1) Linear
#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> par;
	
public:
	DSU(int n) {
		this->par.resize(n);
		for(int i=0; i<n; i++) par[i] = i;
	}
	int get_sp(int x) {
		if(x == par[x]) return x;
		return par[x] = get_sp(par[x]);  
	}
	bool do_union(int x, int y) {
		int sp1 = get_sp(x);
		int sp2 = get_sp(y);
		if(sp1 == sp2) return true;
		if(sp1 != sp2) {           
			par[sp1] = sp2;	
		}
	}
};

int main() {
	int V,E;
	cin>>V>>E;

	DSU obj(V);   // 0 -> n-1 (vertices)
	bool cycle_mila = false;
	for(int i=0; i<E; i++) {
		int x, y;
		cin>>x>>y;
		int sp1 = obj.get_sp(x);
		int sp2 = obj.get_sp(y);

		if(sp1 == sp2) {
			// they are in same component
			cycle_mila = true;
			break;
		}
		else {
			// they are in different component
			obj.do_union(x,y);
		}
	}

	if(cycle_mila) cout<<"Cycle Exists!";
	else cout<<"No Cycle";
	
	return 0;
}