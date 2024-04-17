class Solution {
public:
    int solve(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n = nums.size();
        int l = 0, r = 0, ae = 0, se = 0;
        
        while(r<n){
            se += nums[r];
            
            while(se>goal){
                se-=nums[l];
                l++;
            }
            ae +=r-l+1;
            r++;
        }
        return ae;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int al = solve(nums,goal), sl = solve(nums,goal-1);
      
        return al-sl;
    }
};