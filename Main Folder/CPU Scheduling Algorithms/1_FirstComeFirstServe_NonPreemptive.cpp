// 1_FirstComeFirstServe_NonPreemptive.cpp

// TC = O(N) : as insertion/deletion of every P took place exactly 1 time.
// SC = O(N) : as at max total no of P can arrive at a single point of time.
#include <bits/stdc++.h> 
using namespace std;

void printStat(int *at, int *bt, int *ct, int *tat, int *wt, int n) {
	for(int i=0; i<n; i++) {
		cout<<i<<" "<<at[i]<<" "<<bt[i]<<" "<<ct[i]<<" "<<tat[i]<<" "<<wt[i]<<endl;
	}
	return;
}

int* findCT(int *at, int *bt, int n) {
	queue<pair<int,pair<int,int>>> q;
	for(int i=0; i<n; i++) {
		if(at[i] == 0) q.push({i,{at[i],bt[i]}});
	}

	int* ct = new int[n];
	int curr_time = 0;
	while(!q.empty()) {
		int pid = q.front().first;
		int cat = q.front().second.first;
		int cbt = q.front().second.second;
		q.pop();

				
		ct[pid] = curr_time + cbt;
		for(int i=0; i<n; i++) {
			if(at[i]>curr_time and at[i]<=ct[pid]) 
				q.push({i,{at[i],bt[i]}});
		}	
		curr_time = ct[pid];
	}

	return ct;
}

int* findTAT(int *ct, int *at, int n) {
	// calculating tat
	int total_tat = 0;
	int* tat = new int[n];
	for(int i=0; i<n; i++) {
		tat[i] = ct[i]-at[i];
		total_tat += tat[i];
	}
	return tat;
}

int *findWT(int *tat, int *bt, int n) {
	// calculating wt
	int total_wt = 0;
	int* wt = new int[n];
	for(int i=0; i<n; i++) {
		wt[i] = tat[i]-bt[i];
		total_wt += wt[i];
	}
	return wt;
}

double findAvgTAT(int *tat, int n) {
	double total_tat = 0;
	for(int i=0; i<n; i++) 
		total_tat += tat[i];
	return total_tat/n;
}

double findAvgWT(int *wt, int n) {
	double total_wt = 0;
	for(int i=0; i<n; i++) 
		total_wt += wt[i];
	return total_wt/n;
}

void fcfs_np(int *at, int *bt, int n) {
	// cout<<"im here";
	// 1. Calculate CT
	int *ct = findCT(at,bt,n);
	// cout<<"im here";
	// 2. Calculate TAT
	int *tat = findTAT(ct,at,n);
	// 3. Calculate WT
	int *wt = findWT(tat,bt,n);

	// 4. Print the STATUS
	printStat(at,bt,ct,tat,wt,n);

	// 5. average tat
	cout<<"Average TAT : "<<findAvgTAT(tat,n)<<endl;
	// 6. average wt
	cout<<"Average WT : "<<findAvgWT(wt,n)<<endl;

	return;
}

int main() {
	int at[] = {0,3,5};
	int bt[] = {2,1,6};
	int n = 3;
	// cout<<"IM here";
	fcfs_np(at,bt,n);
	return 0;
}