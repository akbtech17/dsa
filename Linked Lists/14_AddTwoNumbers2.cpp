// 14_AddTwoNumbers2.cpp
// Problem Link - https://leetcode.com/problems/add-two-numbers-ii/
// Code Link - https://ide.codingblocks.com/s/656717
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// A1: Reversing the lists
// TC: O(N)
// SC: O(N)
class Solution {
public:
    void insertNode(ListNode *&head, ListNode *&tail, int val) {
        ListNode *newnode = new ListNode(val);
        if(!head) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
        return;
    }
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while(l1 and l2) {
            int curr = l1->val + l2->val + carry;
            carry = curr/10;
            curr %= 10;
            
            insertNode(head,tail,curr);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            int curr = l1->val + carry;
            carry = curr/10;
            curr %= 10;
            
            insertNode(head,tail,curr);
            l1 = l1->next;
        }
        
        while(l2) {
            int curr = l2->val + carry;
            carry = curr/10;
            curr %= 10;
            
            insertNode(head,tail,curr);
            l2 = l2->next;
        }
        
        while(carry > 0) {
            int curr = carry;
            carry = curr/10;
            curr %= 10;
            
            insertNode(head,tail,curr);
        }
        
        return head;
    }
    ListNode *revList(ListNode *head) {
        if(!head or !head->next) return head;
        
        ListNode *smallList = revList(head->next);
        ListNode *temp = smallList;
        while(temp->next) temp = temp->next;
        temp->next = head;
        head->next = NULL;
        
        return smallList;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rl1 = revList(l1);        
        ListNode *rl2 = revList(l2);
        
        ListNode *rl12 = addTwoNumbers1(rl1,rl2);
        
        return revList(rl12);
    }
};

// A1: Without reversing the lists
// TC: O(N)
// SC: O(1)