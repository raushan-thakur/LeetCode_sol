class Solution {
public:
    void solve(vector<int>& ds, vector<vector<int>>& ans, vector<int>& vis, vector<int>& nums){
        if(ds.size() == vis.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i =0; i<vis.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                ds.push_back(nums[i]);
                solve(ds, ans,vis, nums);
                ds.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(),0);
        solve(ds, ans, vis, nums);
        return ans;
    }
};