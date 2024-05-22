class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        vector < int > hash(256, -1);
        int l=0;
        int r=0;
        int la = 0,ra=0;
        
        while(r<n){
            if(hash[s[r]] != -1){
                    if(hash[s[r]] >=l){
                        l = hash[s[r]] + 1;
                    }
            }
            hash[s[r]] = r;
            // ans = max(ans, r-l+1);
            if(r-l+1 > ans){
                ans = r-l+1;
                la = l;
                ra = r;
            }
            r++;
        }
        cout<<s.substr(la, ra-la+1) << " ";
        return ans;
    }
};
