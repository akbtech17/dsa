// tr2.cpp
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;


int solve(int arr[], int n) {
	int swap = 0;
	for(int i=0; i<n; i++) {
		if((i%3) != (arr[i]%3)) {

			bool ans_mila = false;
			for(int j=i+1;j<n;j++) {
				if((i%3) == (arr[j]%3)) {
					ans_mila = true;
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					swap++;
					break;
				}
			}
			if(!ans_mila) return -1;
		}
	}
	return swap;
}

int main() {
	int arr[] = {2,3,1,1,3,2,2,1,3,3,2,1};
	int n = sizeof(arr)/sizeof(int);
	cout<<solve(arr,n);

}