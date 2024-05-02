class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size(); 
        int ans = -1;
        for(int i = 0; i< n; i++){
            if(nums[i] > ans){
                for(int j =0; j<n; j++){
                    if(nums[j] == -nums[i]) ans=abs(nums[i]);
                }
            }
        }
        return ans;
    }
};