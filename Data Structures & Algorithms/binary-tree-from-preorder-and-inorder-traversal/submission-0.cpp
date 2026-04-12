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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return NULL;
        }
        int val = preorder[0];
        int left_size;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                left_size=i;
                break;
            }
        }
        TreeNode* root = new TreeNode(val);
        vector<int> leftpre(preorder.begin()+1,preorder.begin()+left_size+1);
        vector<int> leftinorder(inorder.begin(),inorder.begin()+left_size);
        vector<int> rightpre(preorder.begin()+left_size+1,preorder.end());
        vector<int> rightinorder(inorder.begin()+left_size+1,inorder.end());
        TreeNode* left = buildTree(leftpre, leftinorder);
        TreeNode* right = buildTree(rightpre, rightinorder);
        root->left=left;
        root->right=right;
        return root;
    }
};
