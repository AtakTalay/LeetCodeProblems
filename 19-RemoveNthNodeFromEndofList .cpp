//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;
        int listSize = 0;
        while(temp != nullptr){
            temp = temp->next;
            listSize++;
        }
        ListNode * prev = nullptr;
        temp = head;
        int count = 0;
        while(count < listSize - n){
            count++;
            prev = temp;
            temp = temp->next;
        }
        if(prev == nullptr){
            head = temp->next;
            delete temp;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }
        return head;
    }
};