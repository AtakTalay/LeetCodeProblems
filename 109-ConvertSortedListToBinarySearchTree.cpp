//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> a;
        ListNode * temp = head;
        while(temp != nullptr){
            a.push_back(temp->val);
            temp = temp->next;
        }
        return helper(a, 0, a.size() );
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