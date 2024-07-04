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
    ListNode* mergeNodes(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* curr = head -> next;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int sum = 0;

        while(curr != NULL){
            sum += curr -> val;
            curr = curr -> next;
            if(curr -> val == 0){
                dummy -> next = new ListNode(sum);
                dummy = dummy -> next;
                curr = curr -> next;
                sum = 0;
            }
        }
        return ans -> next;
    }
};