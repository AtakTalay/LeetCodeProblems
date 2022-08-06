//https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* newHead = new ListNode;
        if(temp1->val < temp2->val){
            newHead->val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            newHead->val = temp2->val;
            temp2 = temp2->next;
        }
        ListNode *temp = newHead;
        while(temp1 != nullptr && temp2 != nullptr){
            ListNode * newNode = new ListNode;
            if(temp1->val < temp2->val){
                newNode->val = temp1->val;
                temp1 = temp1->next;
            }
            else{
                newNode->val = temp2->val;
                temp2 = temp2->next;
            }
            temp->next = newNode;
            temp = newNode;
        }
        while(temp1 != nullptr){
            ListNode * newNode = new ListNode;
            newNode->val = temp1->val;
            temp1 = temp1->next;
            temp->next = newNode;
            temp = newNode;
        }
        while(temp2 != nullptr){
            ListNode * newNode = new ListNode;
            newNode->val = temp2->val;
            temp2 = temp2->next;
            temp->next = newNode;
            temp = newNode;
        }
        return newHead;
    }
};