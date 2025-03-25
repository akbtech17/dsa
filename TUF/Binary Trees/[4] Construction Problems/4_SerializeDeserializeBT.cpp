#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Solution {
public:
	// TC: O(N)
	// SC: O(N)
	string serialize(TreeNode *root) {
		if (root == nullptr) return "";

		string encoded = "";
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop();

			if (node == nullptr) {
				encoded += "#,";
				continue;
			} else {
				encoded += to_string(node->data) + ',';
				q.push(node->left);
				q.push(node->right);
			}
		}
		return encoded;
	}

	TreeNode *deserialize(string data) {
		stringstream s(data);
		string str;

		getline(s, str, ',');
		TreeNode *root = new TreeNode(stoi(str));
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode *currNode = q.front();
			q.pop();

			getline(s, str, ',');
			if (str == "#")
				currNode->left = nullptr;
			else {
				currNode->left = new TreeNode(stoi(str));
				q.push(currNode->left);
			}

			getline(s, str, ',');
			if (str == "#")
				currNode->right = nullptr;
			else {
				currNode->right = new TreeNode(stoi(str));
				q.push(currNode->right);
			}
		}

		return root;
	}
};