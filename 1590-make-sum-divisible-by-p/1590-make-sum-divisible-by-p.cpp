class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
        }
        if (sum == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = INT_MAX, pre = 0;
        for (int i = 0; i < n; i++) {
            pre = (pre + nums[i]) % p;
            if (mp.count((pre - sum + p) % p)) {
                ans = min(ans, i - mp[(pre - sum + p) % p]);
            }
            mp[pre] = i;
        }
        return (ans == n ? -1 : ans);
    }
};