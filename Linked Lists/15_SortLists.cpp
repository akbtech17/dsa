// 15_SortLists.cpp
// Problem Link - https://leetcode.com/problems/sort-list/
// Code Link - https://ide.codingblocks.com/s/656496
#include <bits/stdc++.h>
using namespace std;

// A1: Top Down Merge Sort
// TC: O(NLogN)
// SC: O(NLogN)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode *getMid(ListNode *head) {
        ListNode *s = head, *f = head;
        ListNode *midPrev = NULL;
        while(f and f->next) {
            midPrev = s;
            s = s->next;
            f = f->next->next;
        }
        if(midPrev) midPrev->next = NULL;
        return s;
    }
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        
        if(head1->val<head2->val) {
            head1->next = mergeList(head1->next,head2);
            return head1;
        }
        head2->next = mergeList(head1,head2->next);
        return head2;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode *mid = getMid(head);

        ListNode *left = sortList(head);        
        ListNode *right = sortList(mid);
        
        return mergeList(left,right);
    }
};

// A2: Bottom Up Merge Sort
// TC: O(NLogN)
// SC: O(1)

int main () {
	
}