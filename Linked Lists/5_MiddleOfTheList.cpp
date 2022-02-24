// 5_MiddleOfTheList.cpp
// Problem Link - https://leetcode.com/problems/middle-of-the-linked-list/
// Code Link - https://ide.codingblocks.com/s/636340

// Approach: Two Pointers
// TC: O(N)
// SC: O(1)
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
    ListNode* middleNode(ListNode* head) {
        ListNode *s, *f;
        s = f = head;
        while(f and f->next) {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
};