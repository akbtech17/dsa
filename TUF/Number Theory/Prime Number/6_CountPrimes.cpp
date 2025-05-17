// 6_CountPrimes.cpp
// https://leetcode.com/problems/count-primes/
// https://ide.codingblocks.com/s/640048

// Approach - 
// TC - O(N*Log(Log((N))))
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> sieve(n+1,false);
        
        sieve[0] = sieve[1] = false;
        sieve[2] = true;
        int cnt = 1;
        for(int i=3; i<n; i+=2) 
            sieve[i] = true;

        for(long long int i=3; i<n; i+=2) {
            if(sieve[i]) {
                cnt++;
                for(long long int j=i*i; j<n; j+=2*i) 
                    sieve[j] = false;
            }
        }
        return cnt;
    }
};

int main() {
	Solution S;
	cout<<S.countPrimes(10)<<endl;
	cout<<S.countPrimes(20)<<endl;
	cout<<S.countPrimes(30)<<endl;

	return 0;
}