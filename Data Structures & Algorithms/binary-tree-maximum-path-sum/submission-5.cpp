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
    int maxsum(TreeNode* root){
        if(root==NULL) return 0;
        int mx = max(maxsum(root->left), maxsum(root->right));
        if(mx<0) return max(0,root->val);
        return max(0, root->val +mx);
    }
    int maxel(TreeNode* root){
        if(root==NULL)  return INT_MIN;
        return max(root->val, max(maxel(root->left), maxel(root->right)));
    }
public:
    int maxPathSum2(TreeNode* root) {
        if(root==NULL)  return 0;
        int curr = root->val + maxsum(root->left) + maxsum(root->right);
        return max(curr, max(maxPathSum2(root->left), maxPathSum2(root->right)));
    }
    int maxPathSum(TreeNode* root) {
        int mx = maxel(root);
        if(mx<0)    return mx;
        return max(maxPathSum2(root), mx);
    }
};
