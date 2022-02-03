// 5_LinkedListRandomNode.cpp
// Question - https://leetcode.com/problems/linked-list-random-node/
// Code - 
// Resource - https://www.youtube.com/watch?v=Rl7dOXde_2s
#include <bits/stdc++.h>
using namespace std;

// A1 - using rand() and vector
// TC - O(1)
// SC - O(N)
class Solution1 {
    vector<int> list;
    int n;
public:
    Solution(ListNode* head) {
        srand(time(0));
        while(head) {
            list.push_back(head->val);
            head = head->next;
        }
        n = list.size();
    }
    
    int getRandom() {
        
        int rno = (rand()%n);
        return list[rno];
    }
};

// A2 - 
// TC - O(1)
// SC - O(1)