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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        
        while(!q.empty()){
            level++;
            int n = q.size();
            
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left==NULL && node->right==NULL) return level-1;
                if(node->left!=NULL) q.push(node->left); 
                if(node->right!=NULL) q.push(node->right); 
            }   
        }   
        return level;
    }
};

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         int ans = INT_MAX;
//         dfs(root, ans, 1);
//         return ans==INT_MAX?0:ans;
//     }
    
//     void dfs(TreeNode* root, int& ans, int level){
//         if(root==NULL) return;
//         if(root->left==NULL && root->right==NULL){
//             ans = min(ans,level);
//             return;
//         }
//         dfs(root->left, ans, level+1);
//         dfs(root->right, ans, level+1);
//     }
// };

// class Solution {
// public:
//     int minDepth(TreeNode *root) {
//         if(!root) return 0;
//         if(!root->left) return 1 + minDepth(root->right);
//         if(!root->right) return 1 + minDepth(root->left);
//         return 1+min(minDepth(root->left),minDepth(root->right));
//     }
// };