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
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recur(nums,0,nums.size()-1);
    }
    
    TreeNode* recur(vector<int> &v, int s, int e){
        if(s>e) {
            return NULL;
        }
        
        int idx=s;
        for(int i=s; i<=e; i++){
            if (v[i] > v[idx]){
                idx = i;
            }
        }
        
        TreeNode* root = new TreeNode(v[idx]);
        root->left = recur(v, s, idx-1);
        root->right = recur(v, idx + 1,e);
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         vector<TreeNode*> stk;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             TreeNode* cur = new TreeNode(nums[i]);
//             while (!stk.empty() && stk.back()->val < nums[i])
//             {
//                 cur->left = stk.back();
//                 stk.pop_back();
//             }
//             if (!stk.empty())
//                 stk.back()->right = cur;
//             stk.push_back(cur);
//         }
//         return stk.front();
//     }
// };

