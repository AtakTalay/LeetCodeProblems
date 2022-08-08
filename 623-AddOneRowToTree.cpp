//https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode;
            newRoot->val = val;
            newRoot->left = root;
            return newRoot;
        }
        helper(root, val, depth - 1);
        return root;
    }
    
    void helper(TreeNode * root, int val, int depth){
        if(root == nullptr){
            return;
        }
        if(depth == 1){
            TreeNode * newLeft = new TreeNode;
            TreeNode * newRight = new TreeNode;
            newLeft->val = val;
            newRight->val = val;
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
            return;
        }
        helper(root->left, val, depth - 1);
        helper(root->right, val, depth - 1);
    }
};