// 21_IntersectionOfTwoLinkedLists.cpp
// Problem Link - https://leetcode.com/problems/intersection-of-two-linked-lists/
// Code Link - https://ide.codingblocks.com/s/656760
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Size of List
// TC: O(M+N)
// SC: O(1)
class Solution {
public:
    int getLength(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = getLength(headA);
        int l2 = getLength(headB);
        int diff = abs(l1-l2);
        if(l1>l2) while(diff--) headA = headA->next;
        else while(diff--) headB = headB->next;
        while(headA!=NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};