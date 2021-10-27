// 2_PrimeSieveOfEratosthenes.cpp
// https://ide.codingblocks.com/s/640445

#include <bits/stdc++.h>
using namespace std;


// Approach0 - By the trivial method of checking each isPrime,
//             it will take O(n*sqrt(n))

// Approach1 - Bruteforce of Sieve
// TC - O(NlogN)
// SC - O(N)
class Solution1 {
public:
	void primeSieve(int n) {
		vector<bool> sieve(n+1,false);

		// special cases...
		sieve[0] = sieve[1] = false;
		sieve[2] = true;

		// mark all numbers as prime at initial 
		for(int i=3; i<=n; i++) 
			sieve[i] = true;

		// for every prime number i mark its multiples as non-prime,
		// 2i, 3i, 4i, ...(n/i)floor*i 
		for(long long int i=2; i<=n; i++) {
			if(sieve[i]) {
				for(long long int j=2*i; j<=n; j+=i) 
					sieve[j] = false;
			}
		}

		// print the prime numbers <= n
		for(int i=0; i<=n; i++) {
			if(sieve[i]) cout<<i<<",";
		}
		cout<<endl;
		
		return;
	}
};

// Approach2 - Avoiding Even Numbers and starting multiple loop from i*i 
// TC - O(NlogLogN)
// SC - O(N)
class Solution2 {
public:
	void primeSieve(int n) {
		vector<bool> sieve(n+1,false);

		// special cases...
		sieve[0] = sieve[1] = false;
		sieve[2] = true;

		// 1. mark all numbers as prime at initial 
		// 2. (only odd places),
		//    means all even numbers(except 2) will remain set as non-prime
		for(int i=3; i<=n; i+=2) 
			sieve[i] = true;

		// 1. for every prime number i mark its multiples as non-prime,
		// 2. start the start the non-prime loop from i*i, as prev 
		//    values will pe checked by primes < i
		for(long long int i=3; i<=n; i+=2) {
			if(sieve[i]) {
				for(long long int j=i*i; j<=n; j+=i) 
					sieve[j] = false;
			}
		}

		// print the prime numbers <= n
		for(int i=0; i<=n; i++) {
			if(sieve[i]) cout<<i<<",";
		}
		cout<<endl;
		
		return;
	}
};

// Approach3 - In non-prime loop after starting from i*i check for only odd places
// TC - O(NlogLogN)
// SC - O(N)
class Solution3 {
public:
	void primeSieve(int n) {
		vector<bool> sieve(n+1,false);

		// special cases...
		sieve[0] = sieve[1] = false;
		sieve[2] = true;

		// 1. mark all numbers as prime at initial 
		// 2. (only odd places),
		//    means all even numbers(except 2) will remain set as non-prime
		for(int i=3; i<=n; i+=2) 
			sieve[i] = true;

		// 1. for every prime number i mark its multiples as non-prime,
		// 2. start the start the non-prime loop from i*i, as prev 
		//    values will pe checked by primes < i
		// 3. in non-prime loop after starting from i*i check for only odd places
		for(long long int i=3; i<=n; i+=2) {
			if(sieve[i]) {
				for(long long int j=i*i; j<=n; j+=2*i) 
					sieve[j] = false;
			}
		}

		// print the prime numbers <= n
		for(int i=0; i<=n; i++) {
			if(sieve[i]) cout<<i<<",";
		}
		cout<<endl;

		return;
	}
};

int main() {
	Solution1 S1;
	Solution2 S2;
	Solution3 S3;
	S1.primeSieve(30);
	S2.primeSieve(30);
	S3.primeSieve(30);

	return 0;
}