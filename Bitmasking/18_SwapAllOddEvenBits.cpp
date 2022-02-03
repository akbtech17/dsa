// 18_SwapAllOddEvenBits.cpp
// https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1
// https://ide.codingblocks.com/s/635783

#include <bits/stdc++.h>
using namespace std;

// Approach1 - Bruteforce
// TC - O(1)
// SC - O(1)
class Solution1 {
    public:
    unsigned int swapBits(unsigned int n) {
    	int i = 0;
    	unsigned int num = 0;
    	while(i<63) {
    	    // extract the first bit
    	    int first_bit = (n>>i) & 1;
    	    // extract the second bit
    	    int second_bit = (n>>(i+1)) & 1;
    	    num += (second_bit*pow(2,i)) + (first_bit*pow(2,i+1));
    	   	i+=2;
    	}
    	return num;
    }
};

// Approach2 - Bruteforce
// TC - O(1)
// SC - O(1)
class Solution2 {
    public:
    unsigned int swapBits(unsigned int n) {
    	for(int i=0; i<32; i+=2) {
    		int ith_bit = (n>>i) & 1;        // extracting ith bit
    		int i1th_bit = (n>>(i+1)) & 1;   // extracting i+1th bit

    		n -= (ith_bit<<i);        // deleting the ith bit 
    		n -= (i1th_bit<<(i+1));   // deleting the i+1th bit

    		n += (i1th_bit<<i);       // adding i+1th bit at ith pos
    		n += (ith_bit<<(i+1));    // adding ith bit at i+1th pos
    	}
    	return n;
    }
};


// Approach3 - Using Hex Values
// TC - O(1)
// SC - O(1)
class Solution3 {
public:
    unsigned int swapBits(unsigned int x) {
		// Get all even bits of x
		unsigned int ebits = x & 0xAAAAAAAA;
		// Get all odd bits of x
		unsigned int obits = x & 0x55555555;

		ebits >>= 1;    // Right shift even bits
		obits <<= 1;    // Left shift odd bits
		return (ebits | obits);   // Combine even and odd bits
	}
};

int main() {
	Solution1 S1;
	Solution2 S2;
	Solution3 S3;
	cout<<S1.swapBits(23)<<endl;
	cout<<S2.swapBits(23)<<endl;
	cout<<S3.swapBits(23)<<endl;
	return 0;
}