// 5_PrintPrimesInRange.cpp
// https://hack.codingblocks.com/app/practice/1/388/problem

#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

// Approach - Prime Sieve
// TC - O(NlogLogN)
// Sc - O(N)
class PrimeSieve {
public:
	vector<bool> primeSieve() {
		vector<bool> sieve(MAX,false);

		// special cases...
		sieve[0] = sieve[1] = false;
		sieve[2] = true;

		// 1. mark all numbers as prime at initial 
		// 2. (only odd places),
		//    means all even numbers(except 2) will remain set as non-prime
		for(int i=3; i<=MAX; i+=2) 
			sieve[i] = true;

		// 1. for every prime number i mark its multiples as non-prime,
		// 2. start the start the non-prime loop from i*i, as prev 
		//    values will pe checked by primes < i
		// 3. in non-prime loop after starting from i*i check for only odd places
		for(long long int i=3; i<=MAX; i+=2) {
			if(sieve[i]) {
				for(long long int j=i*i; j<=MAX; j+=2*i) 
					sieve[j] = false;
			}
		}

		return sieve;
	}
};

class Solution {
public:
	void solve() {
		int t;
		cin>>t;

		PrimeSieve ps;
		vector<bool> sieve = ps.primeSieve();

		while(t--) {
			int a,b;
			cin>>a>>b;

			int cnt = 0;
			for(int i=a; i<=b; i++) 
				if(sieve[i]) cout<<i<<endl;

			cout<<endl;
		}
	}
};

int main() {
	Solution S;
	S.solve();
	return 0;
}