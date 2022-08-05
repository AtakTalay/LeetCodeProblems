//https://leetcode.com/problems/add-two-numbers/
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * head = new ListNode;
        head->val = (temp1->val + temp2->val) % 10;
        int remainder = (temp1->val + temp2->val) / 10;
        ListNode * newTemp = head;
        temp1 = temp1->next;
        temp2 = temp2->next;
        ListNode * newNode;
        while(temp1 != nullptr && temp2 != nullptr){
            newNode = new ListNode;
            newNode->val = (temp1->val + temp2->val + remainder) % 10;
            remainder = (temp1->val + temp2->val + remainder) / 10;
            newTemp->next = newNode;
            newTemp = newNode;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != nullptr){
            newNode = new ListNode;
            newNode->val = (temp1->val + remainder) % 10;
            remainder = (temp1->val + remainder) / 10;
            newTemp->next = newNode;
            newTemp = newNode;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            newNode = new ListNode;
            newNode->val = (temp2->val + remainder) % 10;
            remainder = (temp2->val + remainder) / 10;
            newTemp->next = newNode;
            newTemp = newNode;
            temp2 = temp2->next;
        }
        if(remainder != 0){
            newNode = new ListNode;
            newNode->val = 1;
            newTemp->next = newNode;
            newTemp = newNode;
        }
        return head;
    }
};