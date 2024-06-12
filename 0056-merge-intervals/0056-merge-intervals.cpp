class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            auto start = intervals[i];
            int f = start[0];
            int s = start[1];
            while(i + 1 < n && s >= intervals[i + 1][0]) {
                s = max(s, intervals[i + 1][1]);
                i++;
            }
            ans.push_back({f, s});
        }
        return ans;
    }
};
