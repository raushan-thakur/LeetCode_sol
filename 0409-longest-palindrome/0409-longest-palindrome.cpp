class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        
        for(char c : s){
            mp[c]++;
        }
        
        bool odd_found = false;
        for(auto it : mp){
            if(it.second % 2 == 0){
                ans += it.second;
            } else {
                ans += it.second - 1;
                odd_found = true;
            }
        }
        
        if(odd_found) ans++;
        return ans;
    }
};
