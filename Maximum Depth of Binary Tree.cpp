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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 1);
        return ans;
    }
    
    void dfs(TreeNode* root, int& ans, int level){
        if(root==NULL) return;
        ans = max(ans,level);
        dfs(root->left, ans, level+1);
        dfs(root->right, ans, level+1);
    }
};