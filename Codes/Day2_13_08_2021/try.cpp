// try.cpp
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void printPq(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq) {
	while(!pq.empty()) {
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
	}
	return ;
}

int solve(int arr[], int n) {
	// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq0; 
	// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1; 
	// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
	// int n = arr.size();
	// for(int i=0; i<n ;i++) {
	// 	int rem = arr[i]%3;
	// 	if(rem == 0) pq0.push({i,arr[i]});
	// 	else if(rem == 1) pq1.push({i,arr[i]});
	// 	else pq2.push({i,arr[i]});
	// } 
	// printPq(pq0);
	// cout<<endl;
	// printPq(pq1);
	// cout<<endl;
	// printPq(pq2);
	// cout<<endl;
	int swap = 0;
	// int n = arr.size();


	for(int i=0; i<n; i++) {
		if((i%3) != (arr[i]%3)) {
			bool ans_mila = false;
			for(int j=i+1;j<n;j++) {
				if((i%3) != (arr[j]%3)) {
					ans_mila = true;
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					swap++;
				}
			}
			if(!ans_mila) return -1;
		}
		// if((i%3) == 0) pq0.pop();
		// if((i%3) == 1) pq1.pop();
		// if((i%3) == 2) pq2.pop();
		
		// if((arr[i]%3) == (i%3)) {	
		// 	continue;
		// }

		// int rem = i%3;
		// if(rem == 0) {
		// 	if(pq0.empty()) return -1;
		// 	swap++;
		// 	pair<int,int> temp = pq0.top();
		// 	pq0.pop();
		// 	int idx = temp.first;
		// 	arr[idx] = arr[i];
		// 	arr[i] = temp.second;
		// 	if((arr[idx]%3) == 0) pq0.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 1) pq1.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 2) pq2.push({idx,arr[idx]});
		// }
		// else if(rem == 1) {
		// 	if(pq1.empty()) return -1;
		// 	swap++;
		// 	pair<int,int> temp = pq1.top();
		// 	pq1.pop();
		// 	int idx = temp.first;
		// 	arr[idx] = arr[i];
		// 	arr[i] = temp.second;
		// 	if((arr[idx]%3) == 0) pq0.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 1) pq1.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 2) pq2.push({idx,arr[idx]});
		// }
		// else {
		// 	if(pq2.empty()) return -1;
		// 	swap++;
		// 	pair<int,int> temp = pq2.top();
		// 	pq2.pop();
		// 	int idx = temp.first;
		// 	arr[idx] = arr[i];
		// 	arr[i] = temp.second;
		// 	if((arr[idx]%3) == 0) pq0.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 1) pq1.push({idx,arr[idx]});
		// 	if((arr[idx]%3) == 2) pq2.push({idx,arr[idx]});
		// }
	}
	// for(auto el : arr) cout<<el<<" ";
	
	return swap;
}

int main() {
	int arr[] = {3,4,5};
	int n = 3;
	cout<<solve(arr,n);

}