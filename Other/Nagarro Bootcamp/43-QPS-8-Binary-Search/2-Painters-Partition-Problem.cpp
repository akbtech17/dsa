// 2-Painters-Partition-Problem.cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;


// P painters can paint N boards in M amount of times
// or we can say it like that,
// how many painters are required to paint N boards in M time
// if ans <= K then return True

int numberOfPaintersRequired(int P, int N, int* board, int mintime) {
	int painter = 1;
	int time = 0;

	for(int i=0;i<N;i++) {
		time += board[i];
		if(time > mintime) {
			painter++;
			time = board[i];
		}
	}

	return painter;
}

int minTime(int P, int N, int* board) {
	int mx = 0;
	int sum = 0;

	for(int i=0;i<N;i++) {
		sum += board[i];
		mx = max(mx,board[i]);
	}

	int s = mx;
	int e = sum;

	int ans; 
	while(s<=e) {
		int m = (s+e)/2;
		// no of painters required to paint N boards in M time
		// if ans <= K then return True
		if(numberOfPaintersRequired(P,N,board,m)<=P) {
			// minimize the time
			e = m-1;
			ans = m;
		}
		else s = m+1;
	}

	return ans;
}

int32_t main() {
	int N,P;
	cin>>P>>N;
	int* board = new int[N];
	for(int i=0;i<N;i++) cin>>board[i];
	cout<<minTime(P,N,board)<<endl;
	return 0;
}
