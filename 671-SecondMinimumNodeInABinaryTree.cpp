//https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    int findSecondMinimumValue(TreeNode* root) {
        int firstMin = root->val;
        int secondMin = INT_MAX;
        bool changed = false;
        helper(root, firstMin, secondMin, changed);
        if(!changed){
            return -1;
        }
        return secondMin;
    }
    
        
    void helper(TreeNode* root, int& firstMin, int& secondMin, bool& changed){
        if(root == nullptr){
            return;
        }
        if(root->val < firstMin){
            secondMin = firstMin;
            firstMin = root->val;
            changed = true;
        }
        else if(root->val > firstMin){
            changed = true;
            secondMin = min(secondMin, root->val);
        }
        helper(root->left, firstMin, secondMin, changed);
        helper(root->right, firstMin, secondMin, changed);
    }
};