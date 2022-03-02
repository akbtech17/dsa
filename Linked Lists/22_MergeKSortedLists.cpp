// 22_MergeKSortedLists.cpp
// Problem Link - https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/?page=1&difficulty[]=1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions#
// Code Link - https://ide.codingblocks.com/s/656763
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Approach: Using Heaps
// TC: O(NKLogK)
// SC: O(K)
class Solution {
  public:
    Node * mergeKLists(Node *arr[], int K) {
        
        priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
        for(int i=0; i<K; i++) {
            if(arr[i]) {
                pq.push({arr[i]->data,arr[i]});
            }
        }
        
        Node *head = NULL;
        Node *tail = NULL;
        while(!pq.empty()) {
            Node *cnode = pq.top().second;
            pq.pop();
            
            // push the next node
            if(cnode->next) pq.push({cnode->next->data,cnode->next});
            
            // add the cnode in ans
            cnode->next = NULL;
            if(!head) {
                head = tail = cnode;
            }
            else {
                tail->next = cnode;
                tail = cnode;
            }
        }
        
        return head;
    }
};