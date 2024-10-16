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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* headd = NULL;
        ListNode* tail = NULL;
        ListNode* curr = head;

        while(curr){
            if(!s.count(curr->val)){
                ListNode* Node = new ListNode(curr->val);

                if(headd == NULL)
                    headd = tail = Node;
                else{
                    tail->next = Node;
                    tail = Node;
                }    
            }
            curr = curr->next;
        }
        tail->next = NULL;
        return headd;
    }
};