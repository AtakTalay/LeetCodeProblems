//https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode * slowPointer = head;
        ListNode * fastPointer = head->next;
        while(fastPointer != slowPointer){
            if(slowPointer == nullptr  || fastPointer == nullptr){
                return false;
            }
            slowPointer = slowPointer->next;
            if(fastPointer->next != nullptr){
                fastPointer = fastPointer->next->next;
            }
            else{
                fastPointer = nullptr;
            }
        }
        return slowPointer != nullptr;
    }
};