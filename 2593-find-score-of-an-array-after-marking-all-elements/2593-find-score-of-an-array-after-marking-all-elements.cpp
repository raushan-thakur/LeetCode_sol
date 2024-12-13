class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int,int>> pq;

        
        for(int i=0;i<nums.size();i++){
            pq.push({-1*nums[i], -1*i});
        }
        vector<int> vis(nums.size(), 0);
        
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            
            int val = -1*p.first;
            int index = -1*p.second;
            
            if(vis[index]==0){
                if(index+1<nums.size())  vis[index+1]=1;
                if(index-1>=0)  vis[index-1]=1;
                vis[index]=1;
                ans+=val;
            }
            
        }
        
        return ans;
    }
};