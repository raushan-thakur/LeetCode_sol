class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums) mp[it]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto it:mp){
            pq.push({-it.second, it.first});
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            int t = -pq.top().first;
            int n = pq.top().second;
            pq.pop();
            while(t--){
                ans.push_back(n);
            }
        }
        return ans;
    }
};