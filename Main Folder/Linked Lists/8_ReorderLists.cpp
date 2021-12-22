// 8_ReorderLists.cpp
// https://leetcode.com/problems/reorder-list/
// https://ide.codingblocks.com/s/648074
#include <bits/stdc++.h>
using namespace std;


// Approach - Storing the ptrs to the previous nodes and by recursing on the problem.
// TC - O(Nodes)
// SC - O(Nodes) 
class ListNode {
public:
	int val;
	ListNode* next; 

	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    map<ListNode*, ListNode*> prev;
public:
    void buildMap(ListNode* head) {
        ListNode* p = NULL;
        while(head) {
            prev[head] = p;
            p = head;
            head = head->next;
        }
        return;
    }
    void recurse(ListNode* h, ListNode* p, ListNode* t) {
        if(h->next == t or h == t) return;
        
        t->next = h->next;
        h->next = t;
        p->next = NULL;
        
        h = t->next;
        t = prev[t];
        p = prev[t];
        
        recurse(h,p,t);
    }
    void reorderList(ListNode* head) {
        buildMap(head);
        ListNode *t = head, *p = NULL;
        while(t->next) {
            p = t;
            t = t->next;
        }
        recurse(head,p,t);
    }
};

int main() {

}