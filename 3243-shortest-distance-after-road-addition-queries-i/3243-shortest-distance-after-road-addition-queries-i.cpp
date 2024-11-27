class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n);
        vector<int> dp(n), res;
        
        for (int i = 0; i < dp.size(); ++i) dp[i] = i;

        for (const auto &q : queries) {
            v[q[1]].push_back(q[0]);
            for (int i = q[1]; i < n; ++i) {
                dp[i] = min(dp[i], dp[i - 1] + 1);
                for (int l : v[i])
                    dp[i] = min(dp[i], dp[l] + 1);
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};