// mansi1.cpp
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	int ans = 0;
	int max_m = 0;
	for(int m = 1; m < n; m++) {
		int rem = 0;
		if(m*m >= n) rem = (m*m)%n;
		// cout<<rem<<":";
		if(rem > ans) {
			max_m = m;
			// cout<<m<<":";
			ans = rem;
		}
		// ans = max(ans,(m*m)%n);
	}
	return max_m;
}

int main() {
	cout<<endl<<solve(6)<<endl;
	cout<<solve(5)<<endl;
	return 0;
}