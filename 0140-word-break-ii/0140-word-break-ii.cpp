class Solution {
public:
    void solve(int ind, string s, unordered_map<string, int>& mp, vector<string>& ds, vector<string>& ans){
        if(ind == s.size()){
            string sentence = "";
            for (const string& word : ds) {
                if (!sentence.empty()) {
                    sentence += " ";
                }
                sentence += word;
            }
            ans.push_back(sentence);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            string sub = s.substr(ind, i-ind+1);
            if(mp.find(sub) != mp.end()){
                ds.push_back(sub);
                solve(i+1, s, mp, ds, ans);
                ds.pop_back();
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> ds;
        unordered_map<string, int>mp;
        for(auto i: wordDict){
            mp[i]++;
        }
        
        solve(0, s, mp, ds, ans);
        return ans;
    }
};