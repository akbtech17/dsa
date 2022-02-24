// 4_ReverseList2.cpp
// Problem Link - https://leetcode.com/problems/reverse-linked-list-ii/
// Code Link - https://ide.codingblocks.com/s/656567
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// A1: Iterative Reverse List with 2 passes
// TC: O(2N)
// SC: O(1)
class Solution1 {
public:
    int size(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *revList(ListNode *head) {
        if(!head or !head->next) return head;
        
        ListNode *newhead = NULL;
        while(head) {
            ListNode *curr = head;
            head = head->next;
            
            curr->next = newhead;
            newhead = curr;
        }
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next) return head;
        
        int n = size(head);
        if(left == 1 and right == n) return revList(head);
        
        ListNode *head1 = head;
        
        left -= 1;
        right -= 1;
        
        ListNode *tail1 = NULL;
        while(left--) {
            tail1 = head1;
            head1 = head1->next;
        }
        
        ListNode *tail2 = head, *head2 = NULL;
        while(right--) {
            tail2 = tail2->next;
        }
        head2 = tail2->next;
        tail2->next = NULL;
        if(head1 == head) {
            head1 = revList(head);
            head->next = head2;
            return head1;
        }
        else if(head2 == NULL) {
            tail1->next = revList(head1);
            return head;
        }
        else {
            ListNode *rev = revList(head1);
            tail1->next = rev;
            head1->next = head2;
            
            return head;
        }
        
        return NULL;
    }
};

// A2: Iterative Reverse List with single pass
// TC: O(N)
// SC: O(1)
class Solution2 {
public:
    int size(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *revList(ListNode *head, int right, int clen) {
        ListNode *nhead = NULL;
        ListNode *temp = head;
        while(clen<=right) {
            ListNode *cnode = temp;
            temp = temp->next;
            
            cnode->next = nhead;
            nhead = cnode;
            clen++;
        }
        head->next = temp;
        return nhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next) return head;
        ListNode *temp = head;
        int clen = 1;
        left-=1;
        
        ListNode *prev = NULL;
        while(left--) {
            prev = temp;
            temp = temp->next;
            clen++;
        }
        
        if(head == temp) {
            return revList(head,right,clen);
        }
        prev->next = revList(temp,right,clen);
        return head;
    }
};