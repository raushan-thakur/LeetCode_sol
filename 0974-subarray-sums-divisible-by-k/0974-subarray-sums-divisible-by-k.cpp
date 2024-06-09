class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixsum=0,mod=0,count=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        
        for(auto num:nums){
            prefixsum+=num;
            mod= prefixsum % k;
            if(mod<0) mod = mod + k;
            if(mp.find(mod)!=mp.end()){
                count+=mp[mod];
                mp[mod]++;
            }
            else{
                mp[mod]=1;
            }
        }
        return count;
    }
};