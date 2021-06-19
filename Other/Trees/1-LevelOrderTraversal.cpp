// 1-LevelOrderTraversal.cpp
#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
using namespace std;

class Node {
public:
	int val;
	Node *left, *right;
	Node(int val) {
		this->val = val;
		left = right = NULL;
	}
};

void buildTree(Node *&root) {
	root = new Node(1);
	root->left = new Node(3);
	root->right = new Node(2);
	return;
}

vector<int> levelOrder(Node* root){
	queue<Node*> q;
	vector<int> ans;
	if(!root) return ans; 
	q.push(root);

	while(!q.empty()) {
		Node* curr = q.front();
		q.pop();
		if(!curr) {
			q.push()
		}
		ans.pb(curr->val);

		if(curr->left) q.push(curr->left);
		else if(!curr->left and !q.empty()) ()
		if(curr->right) q.push(curr->right);
	}

	return ans;
}
 
int main() {
	Node *root = NULL;
	buildTree(root);

	vi ans = levelOrder(root);

	for(auto el : ans) cout<<el<<" ";

	return 0;
}