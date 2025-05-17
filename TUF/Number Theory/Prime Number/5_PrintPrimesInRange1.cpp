// 5_PrintPrimesInRange.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1
// Code Link - https://ide.codingblocks.com/s/654719

#include <bits/stdc++.h>
using namespace std;

// Approach: Prime Sieve
// TC: O(NlogLogN)
// Sc: O(N)
#define MAX 1000005
class PrimeSieve {
public:
	vector<bool> primeSieve(int b) {
		vector<bool> sieve(b+1,false);

		// special cases...
		sieve[0] = sieve[1] = false;
		sieve[2] = true;

		// 1. mark all numbers as prime at initial 
		// 2. (only odd places),
		//    means all even numbers(except 2) will remain set as non-prime
		for(int i=3; i<=b; i+=2) 
			sieve[i] = true;

		// 1. for every prime number i mark its multiples as non-prime,
		// 2. start the start the non-prime loop from i*i, as prev 
		//    values will pe checked by primes < i
		// 3. in non-prime loop after starting from i*i check for only odd places
		for(long long int i=3; i<=b; i+=2) {
			if(sieve[i]) {
				for(long long int j=i*i; j<=b; j+=2*i) 
					sieve[j] = false;
			}
		}

		return sieve;
	}
};
class Solution {
  public:
    vector<int> primeRange(int a, int b) {
        // code here
        vector<int> ans;
        PrimeSieve ps;
		vector<bool> sieve = ps.primeSieve(b);
        for(int i=a; i<=b; i++) 
				if(sieve[i]) ans.push_back(i);
        return ans;
    }
};

int main() {
	Solution S;
	return 0;
}