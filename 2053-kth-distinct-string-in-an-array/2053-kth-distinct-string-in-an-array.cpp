class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> ans;
        
        unordered_map<string, int> mp;
        
        for(auto it: arr) mp[it]++;
        for(auto it: arr){
            if(mp[it] == 1)ans.push_back(it);
        }

        if(ans.size()<k) return "";
        return ans[k-1];
    }
};