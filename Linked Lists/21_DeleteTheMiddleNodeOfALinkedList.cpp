// 21_DeleteTheMiddleNodeOfALinkedList.cpp
// Question Link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Solution Link - https://ide.codingblocks.com/s/675864
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach : Two Pointers
// TC : O(N)
// SC : O(N)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *s, *f;
        s = f = head;
        
        if(!head or !head->next) return NULL;
        
        f = f->next->next;
        while(f and f->next) {
            s = s->next;
            f = f->next->next;
        }
        s->next = s->next->next;
        return head;
    }
};