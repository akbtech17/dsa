// 8_ReverseNodesInKGroup.cpp
// Problem Link - https://leetcode.com/problems/reverse-nodes-in-k-group/
// Code Link - https://ide.codingblocks.com/s/656618
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Iterative Reverse + Recursion
// TC: O(N)
// SC: O(N)
class Solution {
public:
    ListNode *recurse(ListNode *head, int k, int len, int clen) {
        if(k == 1) return head;
        if(len-clen+1 < k) return head;
        if(!head or !head->next) return head;
        
        ListNode *nhead = NULL;
        ListNode *ntail = head;
        
        int cnt = k;
        while(head and cnt--) {
            ListNode *curr = head;
            head = head->next; 
            
            curr->next = nhead;
            clen++;
            nhead = curr;
        }
        
        ListNode *aageKiList = recurse(head,k,len,clen);
        ntail->next = aageKiList;
        
        return nhead;
    }
    int size(ListNode *head) {
        if(!head) return 0;
        return 1+size(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = size(head);
        return recurse(head,k,len,1);
    }
};