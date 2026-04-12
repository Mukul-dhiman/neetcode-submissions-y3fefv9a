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
    int size(TreeNode* root){
        if(root==NULL)  return 0;
        return 1+max(size(root->left), size(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(abs(size(root->left) - size(root->right)) <= 1){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
};
