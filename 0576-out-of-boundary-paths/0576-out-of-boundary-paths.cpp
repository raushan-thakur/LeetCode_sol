class Solution {
public:
    int MOD = 1000000007;
    int solve(int m,int n,int sr,int sc,int maxMove,vector<vector<vector<int>>>&dp){
        if(sr<0 || sc<0 || sr==m || sc==n) return 1;
        if(maxMove == 0) return 0;
        if(dp[sr][sc][maxMove] != -1) return dp[sr][sc][maxMove];
        
        int ans = 0;
        ans= (ans%MOD + solve(m, n, sr+1, sc, maxMove - 1, dp)%MOD)%MOD;
        ans= (ans%MOD + solve(m, n, sr-1, sc, maxMove - 1, dp)%MOD)%MOD;
        ans= (ans%MOD + solve(m, n, sr, sc+1, maxMove - 1, dp)%MOD)%MOD;
        ans= (ans%MOD + solve(m, n, sr, sc-1, maxMove - 1, dp)%MOD)%MOD;
        
        return dp[sr][sc][maxMove] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int> > > dp(m+1,vector<vector<int> > (n+1, vector<int>(maxMove+1, -1)));
        return solve(m, n , startRow, startColumn, maxMove, dp);
    }
};