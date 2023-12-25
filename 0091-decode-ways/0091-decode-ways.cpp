class Solution {
public:
    int memo[100] = {};
    
    int dp(string& s, int i) {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];
        int ans = 0;
        if (s[i] != '0')
            ans += dp(s, i+1);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) 
            ans += dp(s, i+2);
        return memo[i] = ans;
    }
    
    int numDecodings(string s) {
        return dp(s, 0);
    }
};

