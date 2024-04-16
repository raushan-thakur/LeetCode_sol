class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        vector < int > hash(256, -1);
        int l=0;
        int r=0;
        
        while(r<n){
            if(hash[s[r]] != -1){
                    l= max(hash[s[r]]+1, l);
            }
           hash[s[r]] = r;
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
