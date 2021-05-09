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
    int distributeCoins(TreeNode* root) {
        int ans=0;
        recur (root, ans);
        return ans;
    }
    
    int recur(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int l = recur(root->left, ans);
        int r = recur(root->right, ans);
        
        ans += abs(l) + abs(r);
        
        return root->val + l + r - 1;
    }
};