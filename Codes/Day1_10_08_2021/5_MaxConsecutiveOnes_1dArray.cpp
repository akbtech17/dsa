// 5_MaxConsecutiveOnes_1dArray.cpp
// https://leetcode.com/problems/max-consecutive-ones/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
using std::max;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> nums) {
        int ptr = -1;
        int mxlen = 0;
        for(int i=0; i<nums.size(); i++) {
        	if(nums[i] == 1) {
        		if(ptr == -1) {
        			ptr = i;
        		}
        		mxlen = max(mxlen,i-ptr+1);
        	}
        	else {
        		ptr = -1;
        	}
        }
        return mxlen;
    }
};

int main() {
	Solution sol;
	cout<<sol.findMaxConsecutiveOnes({1,1,0,1,1,1})<<endl;
	cout<<sol.findMaxConsecutiveOnes({1,0,1,1,0,1})<<endl;

	return 0;
}