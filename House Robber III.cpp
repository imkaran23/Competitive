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
    int rob(TreeNode* root) {
        vector<int> ans = recur(root);
        return max(ans[0], ans[1]);
    }
    
    vector<int> recur(TreeNode* root){
        if(root==NULL) return {0,0};
        
        vector<int> left = recur(root->left);
        vector<int> right = recur(root->right);
        vector<int> ans(2);
        
        ans[0] = max(left[0],left[1]) + max(right[0], right[1]);
        ans[1] = root->val + left[0] + right[0];
        
        return ans;
    }
};