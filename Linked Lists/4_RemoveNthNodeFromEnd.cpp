// 4_RemoveNthNodeFromEnd.cpp
// Problem Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Code Link - https://ide.codingblocks.com/s/656504

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Two Pointers
// TC: O(N)
// SC: O(1)
class Solution {
public:
    ListNode *delNode(ListNode *head, ListNode* key) {
        if(key == NULL) return head;
        
        if(head == key) return head->next;
        
        ListNode *prev = NULL;
        ListNode *temp = head;
        while(temp and temp!=key) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        
        delete temp;
        return head;
    }
    ListNode *getNthNode(ListNode *head, int n) {
        ListNode *f, *s;
        f = s = head;
        
        while(f and n--) f = f->next;
        
        while(f) {
            f = f->next;
            s = s->next;
        }
        return s;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *key = getNthNode(head,n);
        return delNode(head,key);
    }
};