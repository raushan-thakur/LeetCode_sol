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
    ListNode* reverse1(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* ret = reverse1(head);
        ListNode* ans = new ListNode(-1);
        ListNode* ans1 = ans;
        int carry = 0;
        
        while(ret){
            int curr = (ret->val)*2 + carry;
            int rem = curr%10;
            carry = curr/10;
            
            ListNode* temp = new ListNode(rem);
            ans->next = temp;
            ans = temp;
            ret = ret->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            ans->next = temp;
            ans = temp;
            carry =0;
        }
        
        ListNode* anstoreturn  = reverse1(ans1->next);
        return anstoreturn;
    }
};