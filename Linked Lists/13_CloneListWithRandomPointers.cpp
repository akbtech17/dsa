// 13_CloneListWithRandomPointers.cpp
// Problem Link - https://leetcode.com/problems/copy-list-with-random-pointer/
// Code Link - https://ide.codingblocks.com/s/639930

// Approach: 3 Steps
// 1 => Insert the Clone Node in-between each ith, (i+1)th node
// 2 => Set the Random Ptrs 
// 3 => Seperate the two lists


// TC: O(N)
// SC: O(1)
#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};


class Solution {
public:
	// Assumption - List is not EMPTY!!!
     Node* copyRandomList(Node* head) {
		// 1. Insert the Clone Node in-between each ith, (i+1)th node
    	Node *curr = head;
    	while(curr) {
    		Node *curr_next = curr->next;
    		Node *newnode = new Node(curr->val);

    		newnode->next = curr_next;
    		curr->next = newnode;

    		curr = curr_next;
    	}

    	// 2. Set the Random Ptrs 
    	curr = head;
    	while(curr) {
    		curr->next->random = curr->random ? curr->random->next : NULL;
    		curr = curr->next ? curr->next->next : NULL;
    	}

    	// 3. Seperate the two lists
    	Node *cloneHead = head ? head->next : NULL;
    	
    	curr = head;
    	Node *copy = cloneHead;
    	while(curr and copy) {
    		curr->next = curr->next ? curr->next->next : NULL;
    		copy->next = copy->next ? copy->next->next : NULL;

    		curr = curr->next;
    		copy = copy->next;
    	}

    	return cloneHead;
    }
    void printList(Node *head) {
		// {current, next, random} =>
		while(head!=NULL) {
			if(head->next and head->random) 
				cout<<"{"<<head->val<<","<<head->next->val<<","<<head->random->val<<"}";
			else if(!head->next and head->random) 
				cout<<"{"<<head->val<<","<<"NULL"<<","<<head->random->val<<"}";
			else if(!head->next and !head->random) 
				cout<<"{"<<head->val<<","<<"NULL"<<","<<"NULL"<<"}";
			else if(head->next and !head->random)
				cout<<"{"<<head->val<<","<<head->next->val<<","<<"NULL"<<"}";
			if(head) cout<<"->";
			head = head->next;
		}
		cout<<endl;
		return;
	}
	void createList(Node *&head) {
		head = new Node(1);
		head->next = new Node(2);
		head->next->next = new Node(3);
		head->next->next->next = new Node(4);

		//1->3
		head->random = head->next->next;
		//2->4
		head->next->random = head->next->next->next;
		//3->1
		head->next->next->random = head;
		//4->2
		head->next->next->next->random = head->next;
	}
};

int main() {
	Solution S;
	Node *head = nullptr;
	S.createList(head);

	Node *cloneHead = S.copyRandomList(head);
	S.printList(head);
	S.printList(cloneHead);

	//comparing the addresses
	Node *p = head;
	Node *q = cloneHead;


	while(p and q) {
		if(p!=q) cout<<"X ";
		p = p->next;
		q = q->next;
	}
	
	return 0;
}