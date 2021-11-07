// 12_SingleNumber3.cpp
// https://leetcode.com/problems/single-number-ii/
#include<bits/stdc++.h>
using namespace std;

// Approach - Using XOR
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int singleNumber(vector<int> nums) {
       	int ans = 0;

       	vector<int> bitmap(64,0);
       	for(auto el : nums) {
       		int num = el, pos = 0;
       		while(num > 0) {
       			bitmap[pos] += (num&1) > 0 ? 1 : 0;
       			num = num>>1;
       			pos++;
       		}
       	}
       	for(int i=0; i<64; i++) {
       		bitmap[i] %= 3;
       		ans += (pow(2,i)*bitmap[i]);
       	}
        return ans;
    }
};

int main() {
	Solution S;
	return 0;
}