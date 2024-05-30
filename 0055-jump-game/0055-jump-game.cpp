class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxWidth = 0;
        
        for(int i =0;i<nums.size(); i++){
            if(maxWidth<i) return false;
            maxWidth = max(maxWidth, i+ nums[i]);
        }
        return true;
    }
};