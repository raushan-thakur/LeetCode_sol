class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans =0;
        int preSum = 0;
        for(int i = 0; i< nums.size(); i++){
            preSum+=nums[i]; 
            if(preSum == k) ans++;
            int rem = preSum - k;
            if(mp[rem]) ans+=mp[rem];
            mp[preSum]++;
        }
        return ans;
    }
};