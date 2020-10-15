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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(v, root);
        return v[k-1];
    }
    
    void inorder(vector<int> &v, TreeNode* root){
        if(root==NULL) return;
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
};

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> st;
//         while(true){
//             while(root!=NULL){
//                 st.push(root);
//                 root = root->left;
//             }
//             root = st.top();
//             st.pop();
//             k--;
//             if(!k) return root->val;
//             root = root->right;
//         }
//         return 0;
//     }
// };