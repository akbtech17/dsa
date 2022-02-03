// 14_RemoveNthNodeFromEndList.cpp
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://ide.codingblocks.com/s/636339

// Approach - Two Pointers
// TC - O(N)
// SC - O(1)
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *prev = NULL, *s, *f;
        s = f = head;
        
        while(f and k--) f = f->next;
        while(f) {
            f = f->next;
            prev = s;
            s = s->next;
        }
        if(prev == NULL) {
            return s->next;
        }
        prev->next = s->next;
        delete s;
        return head;
    }
};