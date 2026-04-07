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
    void trav(TreeNode* root, int curr_max, int& ret){
        if(!root)   return;
        if(root->val>=curr_max){
            ret++;
        }
        curr_max = max(curr_max, root->val);
        trav(root->left, curr_max, ret);
        trav(root->right, curr_max, ret);
    }
public:
    int goodNodes(TreeNode* root) {
        int ret=0;
        trav(root, root->val, ret);
        return ret;
    }
};
