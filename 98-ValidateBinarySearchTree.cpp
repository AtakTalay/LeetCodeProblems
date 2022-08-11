//https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if(root->right == nullptr && root->left == nullptr){
            return true;
        }
        return helper(root, INT64_MIN, INT64_MAX);
    }
    
    bool helper(TreeNode* root, long low, long high){
        if(root == nullptr){
            return true;
        }
        if(root->val < high && root->val > low){
                    return helper(root->left, low, root->val) && helper(root->right, root->val, high);
        }
        return false;
    }
};