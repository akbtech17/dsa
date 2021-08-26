#include<bits/stdc++.h>
using namespace std;


long long int minTime(int batchSize[], int processingTime[], int numTasks[], int n) {
	long long int ans = INT_MIN;
	
	for(int i=0; i<n; i++) {
		// for the current queue, calculate the time required
		int curr_tasks = numTasks[i];
		int curr_Ptime = processingTime[i];
		int curr_Bsize = batchSize[i];
		long long int ctime = 0;
		
		ctime += ((curr_tasks / curr_Bsize)*curr_Ptime);
		if((curr_tasks%curr_Bsize) != 0) ctime+= curr_Ptime;

		ans = max(ctime,ans);
	}

	return ans;
}

int main() {
	int n;
	cin>>n;

	int *bs = new int[n];
	int *pt = new int[n];
	int *nt = new int[n];

	for(int i=0;i<n;i++) cin>>bs[i];
	for(int i=0;i<n;i++) cin>>pt[i];
	for(int i=0;i<n;i++) cin>>nt[i];

	cout<<minTime(bs,pt,nt,n)<<endl;

	return 0;
}