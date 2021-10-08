// 4-IsSubsequence.cpp
// https://leetcode.com/problems/is-subsequence/

#include <iostream>
#include <map>
#include <string>
#include <cstring>
using std::cout;
using std::string;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        if(i == s.size()) return true;
        for(;j<t.size();j++) {
            if(t[j] == s[i]) {
                i++;
            }
            if(i == s.size()) return true;
        }

        return false;
    }
};

int main() {
	Solution s;
	cout<<s.isSubsequence("axc", "ahbgdc");
	return 0;
}