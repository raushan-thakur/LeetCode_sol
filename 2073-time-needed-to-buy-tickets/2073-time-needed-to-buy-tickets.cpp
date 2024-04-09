class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int n = tickets.size();
        for(int i=n-1; i>=0; i--){
            if(i>k){
                ans+=min(tickets[k]-1, tickets[i]);
            }else{
                ans+=min(tickets[k], tickets[i]);
            } 
        }
        return ans;
    }
};