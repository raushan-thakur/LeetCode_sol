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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head->next;
        int firstPost = 0, recentPost = 0, i = 1;
        int minDist = INT_MAX;

        while(cur->next){

            if((cur->val > pre->val && cur->val > cur->next->val) || 
                (cur->val < pre->val && cur->val < cur->next->val)){

                    if(recentPost == 0){
                        firstPost = i;
                        recentPost = i;
                    }
                    else{
                        minDist = min(minDist, i - recentPost);
                        recentPost = i;
                    }
                 
            }
            i++;
            pre = cur;
            cur = cur->next;
        }
        if(minDist == INT_MAX) return {-1,-1};

        return {minDist, recentPost-firstPost};
    }
};