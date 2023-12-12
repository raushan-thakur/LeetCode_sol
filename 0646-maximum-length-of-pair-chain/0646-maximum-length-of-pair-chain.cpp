class Solution {
public:
//     static bool compare(vector<int>&v1,vector<int>&v2){
//         return v1[1]<v2[1];
        
//     }
    int solve(int prev, int i, vector<vector<int>>& pairs, vector<vector<int> >& dp){
        if(i == pairs.size()){
            return 0;
        }
        if(dp[prev +1][i] != -1) return dp[prev+1][i];
        
        int notPick = 0 + solve(prev, i+1, pairs, dp);
        int pick = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            pick = 1 + solve(i, i+1, pairs, dp);
        }
        
        
        int ans = max(pick, notPick);
        return dp[prev +1][i] = ans;
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int> > dp(n+1, vector<int> (n, -1));
        int ans = solve(-1, 0, pairs, dp);
        
        return ans;
    }
};