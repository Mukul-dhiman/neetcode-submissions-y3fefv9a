/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int size(TreeNode* root){
	if(root==NULL) return 0;
	return 1+ size(root->left) + size(root->right);
}
int kthSmallest(TreeNode* root, int k) {
if(k==0 || root==NULL)	return -1;
int left_size = size(root->left);

if(left_size == k-1) return root->val;
if(left_size > k-1)	return kthSmallest(root->left, k);
return kthSmallest(root->right, k - left_size - 1);
 
}

};
