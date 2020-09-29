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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return recur(1, n);
    }
    
    vector<TreeNode*> recur(int l, int r){
        vector<TreeNode*> ans;
        if(l>r) return {nullptr};
        else if (l == r) return { new TreeNode(l) };
        
        for(int i=l; i<=r; i++){
            auto left_subtree = recur(l, i-1);
            auto right_subtree = recur(i+1, r);
            
            for(auto x : left_subtree)
                for(auto y : right_subtree){
                    auto root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
        }
        
        return ans;
    }
};