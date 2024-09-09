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
    
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m, vector<int>(n,-1));
        int startrow=0, endrow=m-1, startcol=0, endcol=n-1;
        
        while(startrow<=endrow and startcol<=endcol and head){
            for(int i=startcol;i<=endcol and head;i++){
                v[startrow][i] = head->val;
                head=head->next;
            }
            startrow++;
            
            for(int i=startrow;i<=endrow and head;i++){
                v[i][endcol] = head->val;
                head=head->next;
            }
            endcol--;
            
            for(int i=endcol;i>=startcol and head;i--){
                v[endrow][i] = head->val;
                head=head->next;
            }
            endrow--;
            
            for(int i=endrow;i>=startrow and head;i--){
                v[i][startcol] = head->val;
                head=head->next;
            }
            startcol++;
        }
        return v;
    }
};