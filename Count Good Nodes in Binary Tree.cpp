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
    int goodNodes(TreeNode* root) {
        int ans = 0, m = INT_MIN;
        dfs(root, ans, m);
        return ans;
    }
    
    void dfs(TreeNode* r, int& ans, int m){
        if(r==NULL) return;
        if(r->val >= m) ans++;
        m = max(m,r->val);
        dfs(r->right, ans, m);
        dfs(r->left, ans, m);
    }
    
    // int goodNodes(TreeNode* root, int val = INT_MIN) {
    // return root == nullptr ? 0 : (val <= root->val) 
    //     + goodNodes(root->left, max(root->val, val))
    //         + goodNodes(root->right, max(root->val, val));
}
};