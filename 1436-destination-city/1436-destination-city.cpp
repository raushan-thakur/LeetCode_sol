class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        unordered_map<string, int> mplast;
        for(auto i: paths){
            mp[i[1]]++;
            mp[i[0]]++;
            mplast[i[1]]++;
        }
        
        for(auto i: mp){
            if(i.second==1  && mplast.find(i.first) != mplast.end())
                return i.first;
        }
        return paths[0][1];
    }
};