// 1-Aggresive-Cows.cpp
// https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
#define int long long
using namespace std;

bool canPlaceCows(int N, int C, int* stalls, int min_dist) {
	// place the first cow at first position
	int prev_pos = stalls[0];
	int palced_cows = 1;
	for(int i = 1; i < N; i++) {
		if(stalls[i]-prev_pos>=min_dist){
			palced_cows++;
			prev_pos = stalls[i];
			if(palced_cows == C) return true;
		}	
	}

	return C == 0;
}

int findMaxMinDist(int N, int C, int* stalls) {
	int s = 0;
	int e = stalls[N-1]-stalls[0];
	int ans;
	// cout<<e;
	
	while(s<=e) {
		int m = (s+e)/2;
		if(canPlaceCows(N, C, stalls, m)) {
			ans = m;
			s = m+1;
		}
		else {
			e = m-1;
		}
	}

	return ans;
}

int32_t main() {
	int t;
	cin>>t;

	while(t--) {
		int N,C;
		cin>>N>>C;

		int* stalls = new int[N];
		for(int i=0;i<N;i++) cin>>stalls[i];
		sort(stalls,stalls+N);
		// cout<<N<<C;
		cout<<findMaxMinDist(N,C,stalls)<<endl;
	}


 	return 0;
}