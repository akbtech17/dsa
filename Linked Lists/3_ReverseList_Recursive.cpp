// 3_ReverseList_Recursive.cpp
// Problem Link - https://leetcode.com/problems/reverse-linked-list/
// Code Link - https://ide.codingblocks.com/s/656518

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Recursive
// TC: O(N)
// SC: O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	// base case
        if(!head or !head->next) return head;
        
        ListNode *smallList = reverseList(head->next);
        
        // do insertion at tail of currnode in smallList
		ListNode *lastNode = smallList;
        while(lastNode->next) lastNode = lastNode->next;
        lastNode->next = head;
        head->next = NULL;

        return smallList;
    }
};