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
    bool isbst(TreeNode* root, int l, int r){
        if(!root)   return true;
        if(!(l<root->val && root->val<r)){
            return false;
        }
        return isbst(root->left, l, root->val) && isbst(root->right, root->val, r);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root, INT_MIN, INT_MAX);        
    }
};
