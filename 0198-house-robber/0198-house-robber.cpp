class Solution {
public:
    int dp[105];
    int f(int n,vector<int>& v){
        if(n<0) return 0;
        if(n == 0) return dp[n]=v[n];
        if(dp[n] != -1) return dp[n];
        
        int take = v[n] + f(n-2,v);
        int ntake = f(n-1,v);
        
        return dp[n] = max(take , ntake);
    }
    
    int rob(vector<int>& v){
        int n = v.size();
        memset(dp,-1,sizeof(dp));
        return f(n-1,v);
    }
};