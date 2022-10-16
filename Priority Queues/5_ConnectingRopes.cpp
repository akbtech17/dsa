// 5_ConnectingRopes.cpp
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
// https://ide.codingblocks.com/s/632745

// TC - O(NlogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(long long arr[], long long n) {
    	priority_queue<long long, vector<long long>, greater<long long>> mnheap;
    	for(int i=0; i<n; i++) 
    		mnheap.push(arr[i]);
		long long cost = 0;
		while(mnheap.size() > 1) {
			long long r1 = mnheap.top();
			mnheap.pop();
			long long r2 = mnheap.top();
			mnheap.pop();
			long long local_cost = r1+r2;
			mnheap.push(local_cost);
			cost += local_cost;
		}	    
		return cost;
    }
};

int main() {
	Solution S;
	long long arr[] = {4, 3, 2, 6};
	cout<<S.minCost(arr,4);
	return 0; 
}