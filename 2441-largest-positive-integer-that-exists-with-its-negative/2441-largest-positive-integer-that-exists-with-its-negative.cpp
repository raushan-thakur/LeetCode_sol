class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> mp(nums.begin(), nums.end());
        
        for(auto it: mp){
            if(mp.find(-it) != mp.end()) ans = max(ans, it);
        }
    return ans;
    }
};