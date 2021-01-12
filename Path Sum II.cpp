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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, sum, root->val, ans, temp);
        return ans;
    }
    
    void dfs(TreeNode* root, int& sum, int s, vector<vector<int>>& ans, vector<int>& temp){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL && s==sum){ 
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        dfs(root->left, sum, s + (root->left!=NULL?root->left->val:0),  ans, temp); 
        dfs(root->right, sum, s + (root->right!=NULL?root->right->val:0), ans, temp);
        temp.pop_back();
    }
};