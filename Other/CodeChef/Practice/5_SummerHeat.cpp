// 5_SummerHeat.cpp
// https://www.codechef.com/problems/COCONUT

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int x,y,X,Y;
		cin>>x>>y>>X>>Y;
		cout<<((X/x)+(Y/y))<<endl;
	}
	return 0;
}