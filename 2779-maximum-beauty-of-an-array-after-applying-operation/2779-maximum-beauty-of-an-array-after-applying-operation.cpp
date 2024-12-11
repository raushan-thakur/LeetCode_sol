class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int left = 0, right = 0, sz = 0;
        while(right < nums.size()) {
            if(nums[right] - nums[left] <= 2*k) {
                right++;
            }
            else {
                left++;
            }
            sz = right-left;
            ans = max(ans, sz);
        }
        return ans;
    }
};