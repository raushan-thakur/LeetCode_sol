class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int x =0, count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            x+=nums[i];
            if(mp[x-goal])
                count+=mp[x-goal];
            mp[x]++;
        }
        return count;
    }
};