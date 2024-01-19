class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n = m.size();
        int ans = INT_MAX;

        vector<int> dp(n);
        vector<int> prevdp(n);
        
        for (int i = 0; i < n; i++) dp[i] = m[0][i];
        
        for (int i = 1; i < n; i++) {
            prevdp = dp;
            for(int  j = 0; j<n; j++){
                int mini = INT_MAX;
                if(j-1 >= 0) mini = min(mini, prevdp[j-1]);
                mini = min(mini, prevdp[j]);
                if(j+1 < n)mini = min(mini, prevdp[j+1]);
                
                dp[j] = mini + m[i][j];
            }
        }
        for(int i =0 ; i < n; i++) ans = min(ans, dp[i]);
        return ans;
    }
};