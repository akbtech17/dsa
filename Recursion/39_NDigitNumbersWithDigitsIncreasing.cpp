// 39_NDigitNumbersWithDigitsIncreasing.cpp
// Question - https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1
// Code - https://ide.codingblocks.com/s/650079
// Resource - https://www.youtube.com/watch?v=nvFh4quEt_c&t=284s
#include <bits/stdc++.h>
using namespace std;

// Approach - Recursion
// TC - O(N!)
// SC - O(N)
class Solution {
    vector<int> ans;
public:
    void recurse(int start, int n, string num = "") {
        if(n == 0) {
            ans.push_back(stoi(num));
            return;
        }
        for(int i=start; i<=9; i++) {
            string nu = num + char('0'+i);
            recurse(i+1, n-1, nu);
        }
        return;
    }
    void printAns() {
        for(auto el: ans) cout<<el<<" ";
    }
    vector<int> increasingNumbers(int n) {
        if(n == 1) recurse(0,n);
        else recurse(1,n);
        printAns();
        return ans;
    }
};

int main() {
    Solution S;
    S.increasingNumbers(2);

    return 0;
}