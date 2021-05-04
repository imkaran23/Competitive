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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* rootCopy = root;
        recur(root, val);
        return rootCopy;
    }
    
    void recur(TreeNode* root, int val){
        while(true){
            if(val>root->val && root->right != NULL) root = root->right;
            else if(val<root->val && root->left != NULL) root = root->left;
            else break;
        }
                
        TreeNode* newNode = new TreeNode(val);
        if(val>root->val) {
            root->right = newNode;
        }
        else {
            root->left = newNode;
        }
    }
};