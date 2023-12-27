class Solution {
public:
    int solve(string &s, vector<int> &t,int i,int prev, vector<vector<int>> &dp){
        if(i == s.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int cost = t[i] + solve(s , t, i+1, prev, dp);
        
        if(prev != (s[i]-'a')){
            cost = min(cost, solve(s,t,i+1,s[i]-'a',dp));
        }
        return dp[i][prev+1]= cost;
        
    }
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>> dp(n,vector<int>(26,-1));
        return solve(colors,neededTime,0,-1,dp);    
    }   
};