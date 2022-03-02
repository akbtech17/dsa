// 20_PartitionList.cpp
// Problem Link - https://leetcode.com/problems/partition-list/
// Code Link - https://ide.codingblocks.com/s/656718
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
    void insertNode(ListNode *&head, ListNode *&tail, ListNode *node) {
        node->next = NULL;
        if(!head) head = tail = node;
        else {tail->next = node; tail = node;}
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1 = NULL, *tail1 = NULL;
        ListNode *head2 = NULL, *tail2 = NULL;
        
        while(head) {
            ListNode *curr = head;
            head = head->next;
            if(curr->val < x) insertNode(head1,tail1,curr);
            else insertNode(head2,tail2,curr);
        }
        
        if(!head1) return head2;
        if(!head2) return head1;
        
        tail1->next = head2;
        return head1;
    }
};