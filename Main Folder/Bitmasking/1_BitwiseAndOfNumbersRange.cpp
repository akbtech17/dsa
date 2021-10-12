// 1_BitwiseAndOfNumbersRange.cpp
// https://leetcode.com/problems/bitwise-and-of-numbers-range/
#include <bits/stdc++.h>
using namespace std;

// bruteforce will not work O(Q*(M-N))


// some observations
// 1 - if any bit flips for a given postion in range [m,n]
//     then entire col & val = 0
// 2 - all the coulumns to the right of the flipped bit is also flipped

// m = 10 -> 1 0 1 0
//           1 0 1 1   
//           1 1 0 0
//           1 1 0 1
// n = 14 -> 1 1 1 0
// ---------------------
//           1 0 0 0

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
    }
};

int main() {

}