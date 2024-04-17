class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int n = nums.size();
        int l=0, r=0, sum = 0, ans=0;
        
        while(r<n){
            sum+=nums[r];
            
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n =nums.size();
        for(int i=0; i<n; i++) nums[i] = nums[i]%2;
        int a = solve(nums, k);
        int b = solve(nums, k-1);

        return a-b;
    }
};