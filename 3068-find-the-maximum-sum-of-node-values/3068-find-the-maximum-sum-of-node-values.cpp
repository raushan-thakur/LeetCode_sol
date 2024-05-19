class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> x(nums.size());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            x[i]=(nums[i]^k)-nums[i];
            ans+=nums[i];
        }
        sort(x.begin(),x.end(),[](auto lhs,auto rhs){
            return lhs>rhs;
        });
        int i=0;
        while(i<x.size()){
            if(i+1<x.size() && x[i]+x[i+1]>0)
                ans+=x[i]+x[i+1];
            else
                break;
            i+=2;
        }
        return ans;
    }
};