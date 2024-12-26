class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int num:nums){
            sum+=num;
        }

        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;

        int s = (sum + target) / 2;
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for(int num:nums){
            for(int j = s;j>=num;j--){
                dp[j] += dp[j-num];
            }
        }

        return dp[s];
    }
};