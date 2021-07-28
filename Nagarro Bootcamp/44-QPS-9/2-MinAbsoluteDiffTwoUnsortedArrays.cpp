// 2-MinAbsoluteDiffTwoUnsortedArrays.cpp
// https://www.geeksforgeeks.org/smallest-difference-pair-values-two-unsorted-arrays/

#include<bits/stdc++.h>
using namespace std;

// O(MlogM + NlogN + M + N)
int minAbsDiff(int* A, int* B, int N) {
	sort(A,A+N);
	sort(B,B+N);
	int i = 0;
	int j = 0;

	int min_diff_so_far = INT_MAX;
	while(i<N and j<N) {
		int cdiff = abs(A[i] - B[j]);
		if(cdiff < min_diff_so_far) {
			if(A[i] < B[j]) i++;
			else j++;
		}
		else {
			if(A[i] > B[j]) i++;
			else j++;
		}
		min_diff_so_far = min(min_diff_so_far, cdiff);
	}

	return min_diff_so_far;
}


// lower bound, first element which is >= key
// check difference with lower idx, and lb-1 idx
// NlogN
int minAbsDiff2(int* A, int* B, int N) {
	// sort only one array
	sort(B,B+N);
	int min_diff_so_far = INT_MAX;

	for(int i=0;i<N;i++) {
		auto lb_itr = lower_bound(B, B+N, A[i]);
		int idx = lb_itr - B;
		int cmin = INT_MAX;
		if(idx == 0) {
			cmin = abs(A[i]-B[idx]);
		}
		else if(idx == N) {
			cmin = abs(A[i]-B[idx-1]);
		}	
		else {
			cmin = min(abs(A[i]-B[idx-1]),abs(A[i]-B[idx]));
		}
		min_diff_so_far = min(min_diff_so_far, cmin);

	}
	return min_diff_so_far;
}

int main() {
	int A[] = {1, 3, 15, 11, 2};
 	int B[] = {23, 127, 235, 19, 8}; 
 	int N = 5;

	// int A[] = {10, 5, 40};
 //    int B[] = {50, 90, 80}; 
 //    int N = 3;
    cout<<minAbsDiff2(A,B,N)<<endl;

    return 0;
}