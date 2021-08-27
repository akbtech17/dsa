// 3_MinCostRopes_Heaps.cpp
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;

class Solution {
    public:
    long long minCost(long long arr[], long long n) {
    	priority_queue<long long, vector<long long>, greater<long long>> pq;
    	long long ans = 0;

    	for(long long i=0; i<n; i++) 
    		pq.push(arr[i]);

    	while(pq.size() >= 2) {
    		long long rope1 = pq.top();
    		pq.pop();
    		long long rope2 = pq.top();
    		pq.pop();
    		ans += (rope1+rope2);
    		pq.push(rope1+rope2);
    	}

    	return ans;
    }
};

int main() {
	Solution S;

	long long arr[] = {4, 3, 2, 6};
	long long n = sizeof(arr)/sizeof(long long);

	cout<<S.minCost(arr,n)<<endl;
	return 0;
}