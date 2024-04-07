class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        vector<int> ans;
        if(c.size()%2 ) return ans;
        sort(c.begin(), c.end());
        
        unordered_map<int, int> mp;
        
        for(int i =0; i<c.size(); i++)mp[c[i]]++;
        
        for(int i = 0 ; i<c.size(); i++){
            if(mp[c[i]] == 0) continue;
            mp[c[i]]--;
            if(mp[c[i]*2] == 0){
                vector<int> a;
                return a;
            }else{
                mp[c[i]*2]--;
            }
            ans.push_back(c[i]);
        }
        return ans;
    }
};