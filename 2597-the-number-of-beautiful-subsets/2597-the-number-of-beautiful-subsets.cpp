class Solution {
public:
    void solve(int ind, vector<int>& nums, int k, int& cnt, unordered_map<int, int>& mp){
        if(ind == nums.size()){
            cnt++;
            return;
        }
        
        if (!mp[nums[ind]-k] && !mp[nums[ind]+k]){
            mp[nums[ind]]++;
            solve(ind+1, nums, k, cnt, mp);
            mp[nums[ind]]--;
        }
        solve(ind+1, nums, k, cnt, mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        solve(0, nums, k, cnt, mp);
        return cnt-1;
    }
};