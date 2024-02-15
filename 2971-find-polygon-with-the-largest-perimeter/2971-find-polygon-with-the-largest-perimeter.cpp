class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long sum = nums[0] + nums[1];
        long maxi = -1;

        for (int i = 2; i < nums.size(); i++) {
            if (sum > nums[i]) {
                maxi = max(maxi, sum + nums[i]);
            }
            sum += nums[i];
        }

        return maxi;  
    }
};