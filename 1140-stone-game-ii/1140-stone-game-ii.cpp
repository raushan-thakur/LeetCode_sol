class Solution {
public:
    
    int recur(vector <int>& a,vector <int>& sufix, int ind, int m, vector < vector <int> >& dp) {
        if (ind == a.size()) return 0;
        if (ind + 2*m >= a.size()) return sufix[ind];
        if (dp[ind][m] != -1) return dp[ind][m];
        int t = INT_MAX;
        for (int k = ind + 1; k <= ind + 2*m; k++) {
            t = min(t, recur(a,sufix, k, max(m, k - ind), dp));
        }
        return dp[ind][m] = sufix[ind] - t;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector <int> sufix(n, 0);
        vector < vector <int> > dp(n+1, vector <int> (n+1, -1));
        sufix[n-1] = piles[n-1];
        for (int i = n - 2; i >-1; i--) {
            sufix[i] = sufix[i + 1] + piles[i];
        }
        return recur(piles, sufix, 0, 1, dp);
        
    }
};