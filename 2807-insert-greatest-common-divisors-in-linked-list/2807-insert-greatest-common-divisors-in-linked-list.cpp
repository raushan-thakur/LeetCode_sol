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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        while (t2) {
            int val = __gcd(t1->val, t2->val);
            ListNode* tmp = new ListNode(val);
            t1->next = tmp;
            tmp->next = t2;
            t1 = t2;
            t2 = t2->next;
        }
        return head;
    }
};