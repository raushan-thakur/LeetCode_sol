class Solution {
public:
    void solve(int i, vector<int>& n, int& ans, int x){
        if(i >= n.size()){
            ans+= x;
            return;
        }
        solve(i+1, n, ans, x^n[i]);
        solve(i+1, n, ans, x); 
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(0, nums, ans, 0);
        return ans;
    }
};