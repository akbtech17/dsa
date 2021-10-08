// 1-LargestIntegerOccursOnlyOnce.cpp
#include<bits/stdc++.h>
using namespace std;

// Find the Largest Unique Number which occurs only once...
// if not -1

// Approach 1
// reverse sort the array, and start itr and check
// first non-repeating element will be our answer
// tc NlogN
// sc - depends on sorting algo
int largestUN1(int *arr, int n) {
	//reverse sort
	sort(arr,arr+n,greater<int>());

	for(int i=0;i<n;i++) {
		if(i==n-1 or arr[i]!=arr[i+1]) return arr[i];
		else {
			//skip all repeating elements
			while(i+1<n and arr[i] == arr[i+1]) i++;
		}
	}

	return -1;
}

// Approach 2
// use maps
// itr over map
// tc - N
// sc - N
int largestUN2(int *arr, int n) {
	int ans = -1;
	unordered_map<int,int> mp;

	for(int i=0;i<n;i++) mp[arr[i]]++;

	for(auto p : mp) {
		if(p.second == 1 and p.first>ans) ans = p.first;
	}
	return ans;
}

int main() {
	int arr[] = {3,3,2,2,1};
	int n = sizeof(arr)/sizeof(n);

	cout<<largestUN1(arr,n)<<endl;
	cout<<largestUN2(arr,n)<<endl;

	return 0;
}