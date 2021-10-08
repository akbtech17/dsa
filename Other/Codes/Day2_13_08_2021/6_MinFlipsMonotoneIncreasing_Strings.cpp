// 6_MinFlipsMonotoneIncreasing_Strings.cpp
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include<iostream>
using std::cout;
using std::endl;
using std::string;
using std::min;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        return 0;
    }
};

int main() {
	Solution S;

	cout<<S.minFlipsMonoIncr("00110")<<endl;
	cout<<S.minFlipsMonoIncr("010110")<<endl;
	cout<<S.minFlipsMonoIncr("0101100011")<<endl;

	return 0;
}