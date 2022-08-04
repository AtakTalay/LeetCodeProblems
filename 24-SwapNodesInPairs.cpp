//https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        if(head->next != nullptr){
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = head;
            head = temp;
        }
        ListNode * prev = head->next;
        ListNode * temp = head->next->next;
        while(temp != nullptr && temp->next != nullptr){
            ListNode* tmp = temp->next;
            temp->next = tmp->next;
            tmp->next = temp;
            temp = tmp;
            prev->next =tmp;
            prev = temp->next;
            temp = temp->next->next;
        }
        return head;
    }
};