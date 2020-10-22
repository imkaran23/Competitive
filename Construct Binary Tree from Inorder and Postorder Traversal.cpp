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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx = inorder.size()-1;
        return build(postorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right ) return NULL;
        int pivot = left; 
        while(inorder[pivot] != postorder[rootIdx]) pivot++;
        
        rootIdx--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        if(left==right) return newNode;
        newNode->right = build(postorder, inorder, rootIdx, pivot+1, right);
        newNode->left = build(postorder, inorder, rootIdx, left, pivot-1);
        return newNode;
    }
};