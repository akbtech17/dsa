// 1_isPrime.cpp
// https://hack.codingblocks.com/app/practice/1/919/problem
// https://ide.codingblocks.com/s/640047

// N is a prime number only when it is div by 1 and N
// or in other words if it is not div by 2...N-1
#include <bits/stdc++.h>
using namespace std;

// Approach1 - check for each 2<i<num if it is div by num or not,
//             if it is div, then not prime, else prime. 
// TC - O(N)
// SC - O(1)
class Solution1 {
public:
	bool isPrime(int num) {
		// special cases...
		// 1. 0 and 1 are neither prime nor composite
		if(num == 0 or num == 1) return false;
		// 2. 2 must also be handled 
		if(num == 2) return true;

		// checking starts from here...
		for(int i=2; i<num; i++) {
			if(num%i == 0) return false;    
		} 
		return true;
	}
};

// Approach2 - insted of runnning a loop from i = 2...N-1 and checking for each itr if the N is not div by i or not
//             we can simply run the loop till N/2 ias no divisor of N wll be greater than N/2
// TC - O(N/2) = O(N)
// SC - O(1)
class Solution2 {
public:
	bool isPrime(int num) {
		// special cases...
		// 1. 0 and 1 are neither prime nor composite
		if(num == 0 or num == 1) return false;
		// 2. 2 must also be handled 
		if(num == 2) return true;
		
		// checking starts from here...
		for(int i=2; i<=num/2; i++) {
			if(num%i == 0) return false;    
		} 
		return true;
	}
};

//Approach3 - insted of runnning a loop till N/2, we can run the loop till sqrt(N)
//            as all divisors oocurs in a pair, if we check till sqrt(N) then automatically
//            all divisors get checked!!! also dont check numbers div by 2
//            2 is the only even prime number.
// TC - O(sqrt(N))
// SC - O(1)
class Solution3 {
public:
	bool isPrime(int num) {
		// special cases...
		// 1. 0 and 1 are neither prime nor composite
		if(num == 0 or num == 1) return false;
		// 2. 2 must also be handled 
		if(num == 2) return true;
		// 3. if num is other than 2 is div by 2, return false
		if(num%2 == 0) return false;
		
		// checking starts from here...(only check for odd nums)
		for(int i=3; i*i<=num; i+=2) {
			if(num%i == 0) return false;    
		} 
		return true;
	}
};


int main() {
	Solution3 S;
	int num;
	cin>>num;
	if(S.isPrime(num)) cout<<"Prime";
	else cout<<"Not Prime";
	
	return 0;
}