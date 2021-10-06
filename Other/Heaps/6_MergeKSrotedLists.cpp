// 6_MergeKSrotedLists.cpp
// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, *tail = NULL;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i]) {
                pq.push({lists[i]->val,i});
                lists[i] = lists[i]->next;
            }
        }
        
        while(!pq.empty()) {
            int el = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            // insert in new list
            ListNode* newnode = new ListNode(el);
            if(!head) {
                head = tail = newnode;
            }
            else {
                tail->next = newnode;
                tail = newnode;
            }
            
            // insert next value
            if(lists[idx]) {
                pq.push({lists[idx]->val,idx});
                lists[idx] = lists[idx]->next;
            }
        }
        return head;
    }
};


int main() {
	Solution S;
	return 0; 
}