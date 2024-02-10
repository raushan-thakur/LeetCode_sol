class Solution {
public:
    bool isPalindrome(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        return s1 == s;
    }
   
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 1; j <= s.length() - i; ++j) {
                string s1 = s.substr(i, j);
                if(isPalindrome(s1)) ans++;
            }
        }
        return ans;
    }
};