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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
            return recur(preorder,0,preorder.size()-1);
    }
    
    TreeNode* recur(vector<int> &v, int s, int e){
        if(s>e){
            return NULL;
        }
        
        int idx=s;
        bool flag = false;
        for(int i=s+1; i<=e; i++){
            if (v[i] > v[idx]){
                flag =true;
                idx = i;
                break;
            }
        } 
        if(!flag) idx = 1+e ;
        
        TreeNode* root = new TreeNode(v[s]);
        root->left = recur(v, s+1, idx-1);
        root->right = recur(v, idx, e);
        return root;
    }

};