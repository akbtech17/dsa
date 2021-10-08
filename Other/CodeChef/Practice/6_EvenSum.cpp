// 6_EvenSum.cpp
// https://www.codechef.com/problems/EVENGAME

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int sum = 0, val;
		for(int i=0;i<n;i++) {
			cin>>val;
			sum += val;
		}
		if(sum%2 == 0) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}