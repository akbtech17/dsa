// 3_PrintNthPrimeNumber.cpp
// https://hack.codingblocks.com/app/practice/1/222/problem
// https://ide.codingblocks.com/s/640448

#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

// Approach - Prime Sieve
// TC - O(NlogLogN)
// SC - O(N)
class Solution {
public:
	void primeSieve(int nth) {
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

		// count the prime number
		int i = 2;
		while(i<=MAX and nth > 0) {
			if(sieve[i]) {
				if(nth == 1) {
					cout<<i;
					break;
				}
				nth--;
			}
			i++;
		}
		return;
	}
};

int main() {
	Solution S;
	
	int nth;
	cin>>nth;
	S.primeSieve(nth);

	return 0;
}