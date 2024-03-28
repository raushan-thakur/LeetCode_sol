class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j =0;
        int n = nums.size();
        unordered_map<int,int> mp;
        
        int ans = 0;
        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] > k){
                while(i<j && mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};