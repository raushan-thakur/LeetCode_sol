class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans =0 ;
        
        for(int i = 0; i<nums.size(); i++){
            int currans=0;
            while(i<nums.size() && nums[i] == 1){
                currans++;
                i++;
            } 
            ans= max(ans, currans);
        }
        return ans;
    }
};