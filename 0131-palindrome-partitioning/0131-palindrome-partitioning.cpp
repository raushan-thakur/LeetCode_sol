class Solution {
public:
    bool isPalindrome(int si, int ei, string s){
        while(si < ei){
            if(s[si] != s[ei]) return false;
            si++;
            ei--;
        }
        return true;
    }
    void solve(int ind, string& s, vector<string>& ds, vector<vector<string>>& ans){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i<s.length(); i++){
            if(isPalindrome(ind, i, s)){
                ds.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        
        solve(0, s, ds, ans);
        return ans;
    }
};