class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        int n=in.size();
        vector<pair<int,int>>arr;
        for(auto it:in){
            arr.push_back({it[0],0});
            arr.push_back({it[1],1});
        }
        sort(arr.begin(),arr.end());
        int cnt=0;
        int ans=0;
        for(auto it:arr){
            if(it.second==0)cnt++;
            else cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};