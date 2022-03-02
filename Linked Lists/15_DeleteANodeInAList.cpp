// 15_DeleteANodeInAList.cpp
// Problem Link - https://leetcode.com/problems/delete-node-in-a-linked-list/
// Code Link - https://ide.codingblocks.com/s/656759
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Swapping
// TC: O(N)
// SC: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev  = NULL;
        while(node and node->next) {
            prev = node;
            node->val = node->next->val;
            node = node->next;
        }
        prev->next = NULL;
        delete node;
    }
};