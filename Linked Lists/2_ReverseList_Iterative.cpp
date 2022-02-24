// 2_ReverseList_Iterative.cpp
// Problem Link - https://leetcode.com/problems/reverse-linked-list/
// Code Link - https://ide.codingblocks.com/s/656511

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Iterative
// TC: O(N)
// SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode *newhead = NULL;
        
        while(head) {
            ListNode *currnode = head;
            head = head->next;
            
            // do insertion at head at newnode
            currnode->next = newhead;
            newhead = currnode;
        }
        
        return newhead;
    }
};