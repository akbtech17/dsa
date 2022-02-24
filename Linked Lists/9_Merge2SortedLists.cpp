// 9_Merge2SortedLists.cpp
// Problem Link - https://leetcode.com/problems/merge-two-sorted-lists/
// Code Link - https://ide.codingblocks.com/s/656498

#include <bits/stdc++.h>
using namespace std;
// Approach: Top Down Recursion
// TC: O(N)
// SC: O(N)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val<list2->val) {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
};