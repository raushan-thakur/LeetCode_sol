class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1 + n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }

        return dp[n];
    }
};