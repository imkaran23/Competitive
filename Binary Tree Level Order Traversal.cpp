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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;
        q.push(root);
        ans.push_back({root->val});
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left); 
                    temp.push_back(node->left->val);
                }
                if(node->right!=NULL){
                    q.push(node->right); 
                    temp.push_back(node->right->val);
                }
            }   
            if(temp.size()){ 
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
    }
};