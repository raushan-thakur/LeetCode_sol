class Solution {
public:
    int space(vector<int>& nums){
        int n = nums.size();
        
        vector<int> c(n+1, 0);
        vector<int> p(n+1, 0);

        for(int curr = n-1; curr>=0 ;curr--){
            for(int prev = curr; prev>=-1; prev--){
                int notTake = 0 + c[prev+1];
                int take = 0; 
                if(prev==-1 || nums[prev]<nums[curr]){
                    take = 1 + c[curr+1];
                }
                p[prev+1] = max(take, notTake);
            }
            c = p;
        }
        return c[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return space(nums);
    }
};