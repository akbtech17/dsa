// 8-InvertBinaryTree.cpp
// https://leetcode.com/problems/invert-binary-tree/

TreeNode* invertTree(TreeNode* root) {
	if(!root) return NULL;
	TreeNode* newroot = new TreeNode(root->val);
	newroot->right = invertTree(root->left);
	newroot->left = invertTree(root->right);

	return newroot;
}