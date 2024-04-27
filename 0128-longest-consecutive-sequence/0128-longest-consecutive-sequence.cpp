class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int ans= 1;
        int cnt =1;
        for(int i= 1; i<nums.size(); i++){
            if(nums[i] == last+1){
                last = nums[i];
                ans = max(ans, ++cnt);
            }else if (nums[i] != last){
                last = nums[i];
                cnt =1;
            }
        }
        return ans;
    }
};