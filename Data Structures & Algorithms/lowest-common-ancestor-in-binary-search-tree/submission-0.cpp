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
    bool find(TreeNode* root, TreeNode* x){
	if(!root) return false;
	if(root==x) return true;
	return find(root->left, x) || find(root->right, x);
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        	
            if(!root){
		return NULL;
	}
    // cout<<root->val<<endl;
	if(root==q || root==p){
		return root;
	}
	bool qleft=find(root->left, q), pleft = find(root->left, p);
	if(qleft!=pleft) return root;
	if(qleft==true && pleft==true) return lowestCommonAncestor(root->left, p,q);
return lowestCommonAncestor(root->right, p,q);
    }
};
