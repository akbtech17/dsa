// 4-IntersectingPointOfLists.cpp
#include <iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* findIntersection1(ListNode* L1, ListNode *L2) {
	while(L1!=NULL) {
		ListNode *temp = L2;
		while(temp) {
			if(temp == L1) return temp;
			temp = temp->next;
		}
		L1 = L1->next;
	}
	return NULL;
}

int len(ListNode* List) {
	int n = 0;
	while(List) {
		List = List->next;
		n++;
	}
	return n;
}

ListNode* findIntersection2(ListNode* L1, ListNode *L2) {
	int l1 = len(L1);
	int l2 = len(L2);

	if(l1!=l2) {
		if(l1>l2) {
			int diff = l1-l2;
			while(diff--) {
				L1 = L1->next;
			}
		}
		else {
			int diff = l2-l1;
			while(diff--) {
				L2 = L2->next;
			}
		}
	}

	while(L1 and L2) {
		if(L1 == L2) return L1;
		L1=L1->next;
		L2=L2->next;
	}

	return NULL;
}



int main() {

	return 0;

}