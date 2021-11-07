// 11_SingleNumber2.cpp
// https://leetcode.com/problems/single-number-iii/
// https://ide.codingblocks.com/s/642418
#include<bits/stdc++.h>
using namespace std;

// Approach - Using XOR
// TC - O(N)
// SC - O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int> nums) {
        vector<int> ans;

        int xrNum = 0; // to store the xor of all numbers
        for(auto el : nums) xrNum ^= el; // a^b

        // finding the location of first set bit (different bit in a and b)
        int temp = xrNum;
    	int bitPos = 0;
    	while((temp&1)!=1) {
    		bitPos++;
    		temp = temp>>1;
    	}

    	// now seperate the two sets of numbers, 
    	// 1. set with the found bit
    	// 2. set without the found bit

    	int set1 = 0;   // a
    	int set2 = 0;   // b

    	int mask = 1<<(bitPos);

    	// seperating the sets
    	for(auto el : nums) {
    		if((el&mask) == 0) set1 ^= el;   // a
    		else set2 ^= el;  // b
    	}

        return {set1,set2};
    }
};

int main() {
	Solution S;
	return 0;
}