class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0 ;
        int n = nums.size();
        for(int i=1; i<=n; i++) num=num^i;
        for(int i =0;i<n;i++) num = num^nums[i];
        
        return num;
    }
};