class Solution {
public:
    int val;
    map<int,int>mp;
    int countMaxOrSubsets(vector<int>& nums){   
         val=INT_MIN;
         int idx=0;
         f(nums,idx,0);
         return mp[val];
    }
    void f(vector<int>&nums,int idx,int ele){
        if(idx >= nums.size()){
            val=max(val,ele);
            mp[ele]++;
            return;
        }
        f(nums,idx+1,ele|nums[idx]);
        f(nums,idx+1,ele);
    }
};