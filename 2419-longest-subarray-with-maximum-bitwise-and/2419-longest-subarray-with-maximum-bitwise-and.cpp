class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int maxVal = 0;
        int maxLen = 0;

        for(int num:nums){
            if(num>maxVal){
                maxVal = num;
                maxLen = 0;
                ans = 0;
            }

            if(maxVal == num){
                maxLen++;
            }else{
                maxLen = 0;
            }

            ans = max(ans, maxLen);
        }
        return ans;
    }
};