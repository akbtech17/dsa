// vw4-max-consecutive-ones.cpp
// https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> nums) {
        int n = nums.size();
        int ans = 0;
        int s = -1;
        int e = 0;
        while(e < n) {
            if(nums[e] == 0) s = e;
            ans = max(e-s, ans);
            e++;
        }
        return ans;
    }
};

int main() {
	Solution S;
	cout<<S.findMaxConsecutiveOnes({1,1,0,1,1,1})<<endl;
	cout<<S.findMaxConsecutiveOnes({1,0,1,1,0,1})<<endl;

	return 0;

}