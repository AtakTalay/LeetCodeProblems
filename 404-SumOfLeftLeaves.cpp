//https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        helper(root, false, total);
        return total;
    }
    
    void helper(TreeNode* root, bool isLeft, int& total){
        if(root == nullptr){
            return;
        }
        if(isLeft){
            if(root->left == nullptr && root->right == nullptr){
                total += root->val;
            }
        }
        helper(root->left, true, total);
        helper(root->right, false, total);
    }
};