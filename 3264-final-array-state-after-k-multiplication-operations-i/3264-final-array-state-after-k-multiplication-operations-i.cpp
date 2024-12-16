class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({-nums[i], -i});
        }
        
        while(k--){
            auto top = pq.top();
            pq.pop();
            int num = -top.first;
            pq.push({-num*multiplier, top.second});
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int num = -top.first;
            int i = -top.second;
            nums[i]=num;
        }

       return nums; 
    }
};