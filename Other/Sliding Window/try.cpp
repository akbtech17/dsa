// try.cpp

#include<bits/stdc++.h>
using namespace std;

void firstNegativeInteger(int *arr, int n, int k) {

	int s = 0;
	int e = 0;
	queue<int> q;
	while(e<n) {
		// add calculation for the current element
		if(arr[e]<0) q.push(arr[e]);
		int ws = e-s+1;
		if(ws < k) {
			e++;
		}
		else if(ws == k) {
			if(q.empty()) cout<<0<<endl;
			else cout<<q.front()<<endl;

			if(!q.empty() and arr[s] == q.front()) {
				q.pop();
			}
			s++;
			e++;
		}
	}


	return ;
} 

int main () {
	int arr[] = {-8, 2, 3, -6, 10};
	int k = 2;
	int n = sizeof(arr)/sizeof(int);
	firstNegativeInteger(arr, n, k);
	return 0;
}