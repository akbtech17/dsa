// 3-Roti-Patra.cpp
// https://www.spoj.com/problems/PRATA/
#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cooksRequired(int P, int L, int* ranks, int mtime) {
	int patras_completed = 0;

	for(int cook=0;cook<L;cook++) {
		int time_elapsed = 0;
		int i = 1;
		while(time_elapsed<mtime) {
			patras_completed++;
			time_elapsed += ranks[cook]*i;
			i++;
			if(time_elapsed > mtime) patras_completed--;
		}
	}

	return patras_completed>=P;
 }

int minTime(int P, int L, int* ranks) {
	int s = 0;
	int e = 0;
	// patras_done = 0;
	// for(int cook=0;cook<L;cook++) {
	// 	if(patras_done<P) {
	// 		rank
	// 	}
	// }
	for(int i=1;i<=P;i++) {
		// s+=ranks[0]*i;
		e+=ranks[L-1]*i;
	}
	// cout<<s<<" "<<e;
	int ans;
	while(s<=e) {
		int m = (s+e)/2;
		// cout<<m<<endl;
		if(cooksRequired(P,L,ranks,m)) {
			e = m-1;
			ans = m;
		}
		else s = m+1;
	}

	return ans;
}

// 1
// 8
// 8 1 1 1 1 1 1 1 1

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int P, L;
		cin>>P>>L;

		int* ranks = new int[L];

		for(int i=0;i<L;i++) cin>>ranks[i];
		sort(ranks,ranks+L);
		cout<<minTime(P,L,ranks)<<endl;
	}

	return 0;
}