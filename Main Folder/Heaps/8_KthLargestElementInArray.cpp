// 8_KthLargestElementInArray.cpp
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// https://ide.codingblocks.com/s/632750

// TC - O(N + KlogN)
// SC - O(N)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto el: nums) pq.push(el);
        while(k != 1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};