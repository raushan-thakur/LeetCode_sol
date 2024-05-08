class Solution {
public:
    void solve(int i, int x, vector<int>& a, vector<vector<int>>& ans, vector<int>&ds){
        if(i == a.size()){
            if(x == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(a[i] <= x){
            ds.push_back(a[i]);
            solve(i, x-a[i], a, ans, ds);
            ds.pop_back();
        }
        solve(i+1, x, a, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ans, ds);
        return ans;
    }
};