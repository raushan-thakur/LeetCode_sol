class Solution {
public:
    void solve(int i, int x, vector<int>& a, set<vector<int>>& ans, vector<int>&ds){
        if(i == a.size()){
            if(x == 0){
                ans.insert(ds);
            }
            return;
        }
        
        if(a[i] <= x){
            ds.push_back(a[i]);
            solve(i+1, x-a[i], a, ans, ds);
            ds.pop_back();
        }
        while (i + 1 < a.size() && a[i + 1] == a[i]) {
        i++;
    }
        solve(i+1, x, a, ans, ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ans, ds);
        vector<vector<int>> ans1;
        for(auto it : ans) ans1.push_back(it);
        return ans1;
    }
};