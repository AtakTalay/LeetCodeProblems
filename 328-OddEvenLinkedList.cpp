//https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* oddPointer = head;
        ListNode* evPovTail = head->next;
        ListNode* evenPointer = head->next;
        while(evenPointer != nullptr && evenPointer->next != nullptr){
            oddPointer->next = evenPointer->next;
            evenPointer->next = evenPointer->next->next;
            oddPointer->next->next = evPovTail;
            evenPointer = evenPointer->next;
            oddPointer = oddPointer->next;
        }

        return head;
    }
};