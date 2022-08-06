//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() );
    }
    
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if(high <= low){
            return nullptr;
        }
        TreeNode * newNode = new TreeNode;
        newNode->val = nums[(low + high) / 2];
        newNode->left = helper(nums, low, (low + high) / 2);
        newNode->right = helper(nums, (low + high) / 2 + 1, high);
        return newNode;
    }
};