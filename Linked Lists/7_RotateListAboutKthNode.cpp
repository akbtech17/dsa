// 7_RotateListAboutKthNode.cpp
// Problem Link - https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// Code Link - https://ide.codingblocks.com/s/656612
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach: Manipulation of Pointers
// TC: O(N)
// SC: O(1)
class Solution {
public:
    ListNode* rotate(ListNode* head, int k) {
        ListNode *temp = head, *prev = NULL;
        if(k == 0) return head;
    
        while(k>0) {
            prev = temp;
            temp = temp->next;
            k--;
        }
        if(prev) prev->next = NULL;
        if(!temp and head) return head;
        
        ListNode *tail = temp;
        while(tail->next) tail = tail->next;
        tail->next = head;
        
        return temp;
    }
};
