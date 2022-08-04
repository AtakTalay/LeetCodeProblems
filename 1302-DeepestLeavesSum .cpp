//https://leetcode.com/problems/deepest-leaves-sum/
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
    int calcHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(calcHeight(root->right), calcHeight(root->left));
    }

    void calcSum(TreeNode * root, int& total, int depth, int height){
        if(root == nullptr){
            return;
        }
        if(depth == height){
            total += root->val;
            return;
        }
        calcSum(root->right, total, depth + 1, height);
        calcSum(root->left, total, depth + 1, height);
    }

    int deepestLeavesSum(TreeNode* root) {
        int total = 0;
        int height = calcHeight(root);
        calcSum(root, total, 1, height);
        return total;
    }

};