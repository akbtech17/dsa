// 3_SameDifferences.cpp
// Question Link - https://codeforces.com/contest/1520/problem/D
// Solution Link - https://ide.codingblocks.com/s/654319
#include <bits/stdc++.h>
#define int long long
using namespace std;

// Approach: Using HMap
//           we have to find i,j where i<j and i!=j
//           also arr[j]-arr[i] = j-i
//           which we can rewrite as arr[j]-j = arr[i]-i
// TC: O(T*N)
// SC: O(N)

int solve(int *arr, int n) {
	int cnt = 0;
	unordered_map<int,int> mp;

	mp[arr[n-1]-n+1] = 1;
	for(int i=n-2; i>=0; i--) {
		int key = arr[i]-i;
		cnt += mp[key];
		mp[key]++;
	}

	return cnt;
}

int32_t main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr = new int[n];
		for(int i=0; i<n; i++) cin>>arr[i];
		cout<<solve(arr,n)<<endl;
	}
	return 0;
}