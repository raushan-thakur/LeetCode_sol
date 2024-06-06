class Solution {
public:
    bool isNStraightHand(vector<int>&v,int k) {
        map<int,int>mp;
        for(auto it:v) mp[it]++;
        for(auto [num,freq]:mp){
            if(!freq) continue;
            for(int j=num+k-1;j>=num;j--){
                if(mp[j]<freq) return 0;
                mp[j]-=freq;
            }
        }
        return 1;
    }
};