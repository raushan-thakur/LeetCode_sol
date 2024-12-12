class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto it:gifts) pq.push(it);
        for(int i=0; i<k; i++){
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        
        long long ans = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans+=top;
        }
        return ans;
    }
};