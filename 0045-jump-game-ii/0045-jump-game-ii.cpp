class Solution {
public:
    long long int solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind >= nums.size()-1) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long int ans = INT_MAX;
        for(int i=1; i<=nums[ind]; i++){
            long long int curr = solve(ind+i, nums, dp) + 1;
            ans = min(ans, curr);
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(0, nums, dp);
    }
};
