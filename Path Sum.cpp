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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        return dfs(root, sum, root->val);
    }
    
    bool dfs(TreeNode* root, int& sum, int s){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && s==sum) return true;
        return dfs(root->left, sum, s + (root->left!=NULL?root->left->val:0)) || 
               dfs(root->right, sum, s + (root->right!=NULL?root->right->val:0));
    }
};