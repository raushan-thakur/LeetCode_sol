class Solution {
public:
    int solve(vector<int>& nums, int curr, int prev, vector<vector<int> >& dp){
        if(curr == nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        
        int notTake = 0 + solve(nums, curr+1, prev, dp);
        int take = 0; 
        if(prev==-1 || nums[prev]<nums[curr]){
            take = 1 + solve(nums, curr+1, curr, dp);
        }
        
        int ans = max(take, notTake);
        return dp[curr][prev+1] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int> (n, -1));
        return solve(nums,0,-1, dp);
    }
};