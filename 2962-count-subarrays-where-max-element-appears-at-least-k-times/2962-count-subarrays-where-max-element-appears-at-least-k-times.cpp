class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long i =0 , j=0, n=nums.size(), freq=0, maxi=0, ans=0;
        
        for(auto it : nums){
            if(it>maxi)  maxi = it;
        }
        
        while(j<n){
            if(nums[j] == maxi) freq++;
            while(freq >= k){
                ans+=n-j;
                if(nums[i] == maxi) freq--;
                i++;
            }
            j++;
        }
        return ans;
    }
};