// 18_ReverseNodesInEvenLength.cpp
// Problem Link - https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
// Code Link - https://ide.codingblocks.com/s/656616
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
        if(!head or !head->next) return head;
        int nodes_left = len-clen+1;
        
        if((nodes_left>=k and k%2==0) or (nodes_left < k and (nodes_left%2) == 0)) {
            // reverse next k nodes
            ListNode *nhead = NULL;
            ListNode *ntail = head;
            int cnt = k;
            
            while(head and cnt--) {
                clen++;
                ListNode *curr = head;
                head = head->next;
                
                curr->next = nhead;
                nhead = curr;
            }
            
            ntail->next = recurse(head,k+1,len,clen);
            return nhead;
        }
        // else move k nodes
        int cnt = k; 
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp and cnt--) {
            clen++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = recurse(temp,k+1,len,clen);
        
        return head;
    }
    
    int size(ListNode *head) {
        if(!head) return 0;
        return 1 + size(head->next);
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int len = size(head);
        return recurse(head,1,len,1);
    }
};