class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < d.size(); ++i) {
            jobs.push_back({d[i], p[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(w.begin(), w.end());

        int ans = 0;
        int maxProfit = 0;
        int j = 0;  
        
        for (int i = 0; i < w.size(); ++i) {
            while (j < jobs.size() && jobs[j].first <= w[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                ++j;
            }
            ans += maxProfit;
        }
        
        return ans;
    }
};