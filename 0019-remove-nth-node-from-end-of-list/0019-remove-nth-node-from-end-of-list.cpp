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
        int length = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* current = head;
        while (current != NULL) {
            length++;
            current = current->next;
        }

        length -= n;
        current = dummy;
        while (length > 0) {
            length--;
            current = current->next;
        }

        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;

        return dummy->next;
    }
};
