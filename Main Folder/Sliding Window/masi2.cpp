#include <bits/stdc++.h>
using namespace std;

int findsum(int n) {
	int sum = (n*(n+1))/2;
	return sum;
}

int solve(int n) {
	int sum = 0;
	for(int i=0; i<n ;i++) {
		sum += findsum(i+1);
	}
	return sum;
}

int main() {
	cout<<solve(4);
	return 0;
}