class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        vector<int> ans;
        
        for(int i = 0; i< nums.size();i++) mul=mul*nums[i];
        
         for(int i = 0; i< nums.size();i++){
             if(nums[i]!=0){
                 int temp = mul/nums[i];
                 ans.push_back(temp);
             }else{
                 int temp = 1;
                 for(int j = 0; j< nums.size();j++){
                    if(j==i) continue;
                    temp*=nums[j];
                 }
                 ans.push_back(temp);
             }
            
        }
        return ans;
    }
};