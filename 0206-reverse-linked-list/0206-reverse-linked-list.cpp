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
    ListNode* rev(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* smallHead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallHead;
        
    }
    ListNode* reverseList(ListNode* head) {
        //return rev(head);
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev= NULL;
        ListNode* curr=head;
        ListNode* forward = curr->next;
        
        while(curr != NULL){
            forward = curr->next;
            curr->next=prev;
            prev = curr; 
            curr = forward;
        }
        return prev;
    }
};