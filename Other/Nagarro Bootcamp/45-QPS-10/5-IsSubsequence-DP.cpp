// 5-IsSubsequence-DP.cpp
// https://leetcode.com/problems/is-subsequence/

#include <iostream>
#include <map>
#include <string>
#include <cstring>
using std::cout;
using std::string;


// recursive

// f(i,j) - returns if there exists a subsequence in t[i...n-1] that matches s[j...m-1]
// if i == j -> return f(i+1,j+1)
// else return f(i+1,j)

// base case - 

// if j == m return true
// if i == n return false

class Solution2 {
public:
    bool isSubsequence(string s, string t) {
        
        return false;
    }
};