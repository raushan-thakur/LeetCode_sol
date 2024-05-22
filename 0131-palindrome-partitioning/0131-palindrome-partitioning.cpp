class Solution {
public:
    bool isPalindrome(string s, int low, int high){
        while(low<high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(int ind, string& s, vector<string>& ds, vector<vector<string>>& ans){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i<s.length(); i++){
            if(isPalindrome(s, ind, i)){
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