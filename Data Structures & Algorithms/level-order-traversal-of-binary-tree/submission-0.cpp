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
    void trav(TreeNode* root, int level, vector<vector<int>>& ret){
        if(root==NULL){
            return;
        }
        if(ret.size()<level){
            ret.push_back({root->val});
        }
        else{
            ret[level-1].push_back(root->val);
        }
        trav(root->left, level+1, ret);
        trav(root->right, level+1, ret);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        trav(root, 1, ret);
        return ret;
    }
};
