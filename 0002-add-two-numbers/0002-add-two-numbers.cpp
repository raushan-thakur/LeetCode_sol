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
        ListNode* ans = new ListNode(-1);
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* l = ans;
        int carry =0;
        
        while(l1!= NULL || l2!= NULL){
            int sum = carry ;
            if(l1) sum+=l1->val ;
            if(l2) sum+=l2->val;
            carry = sum/10;
            
            ListNode* temp = new ListNode(sum%10);
            l->next = temp;
            l=l->next;
            
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            l->next = temp;
            l=l->next;
        }
        return ans->next;
    }
};