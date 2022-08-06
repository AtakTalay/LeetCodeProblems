//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        helper(root, root->val, root->val, maxDiff);
        return maxDiff;
    }
    
    void helper(TreeNode * root, int minNode, int maxNode, int& maxDiff){
        if(root == nullptr){
            return;
        }
        minNode = min(minNode, root->val);
        maxNode = max(maxNode, root->val);
        maxDiff = max(maxDiff, maxNode - minNode);
        helper(root->left, minNode, maxNode, maxDiff);
        helper(root->right, minNode, maxNode, maxDiff);
    }
};