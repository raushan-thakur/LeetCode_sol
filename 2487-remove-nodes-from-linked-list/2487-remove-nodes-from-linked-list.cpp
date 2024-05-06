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
    ListNode* removeNodes(ListNode* head) {
        
        vector<int> a;
        ListNode* temp = head;
        while(temp){
            a.push_back(temp->val);
            temp= temp->next;
        }
        stack<int> st;
        int maxi = a[a.size()-1];
        for(int i = a.size()-1; i>=0; i--){
            if(maxi<=a[i]){
                st.push(a[i]);
                maxi = a[i];
            }
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* ans1 = ans;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ListNode* temp = new ListNode(top);
            ans1 ->next = temp;
            ans1 = ans1->next;
        }
        return ans->next;
    }
};