// 39_NDigitNumbersWithDigitsIncreasing.cpp
// Question - https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1
// Code - 
// Resource - https://www.youtube.com/watch?v=nvFh4quEt_c&t=284s
#include <bits/stdc++.h>
using namespace std;

// Approach - Recursion
// TC - O()
// SC - O()
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
    vector<int> increasingNumbers(int n) {
        if(n == 1) recurse(0,n);
        else recurse(1,n);
        return ans;
    }
};

int main() {

}