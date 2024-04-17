class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        vector<int> f(26,0);
        int maxi = 0;
        int l =0;
        int r=0;
        
        while(r<n){
            f[s[r] - 'A']++;
            maxi = max(maxi, f[s[r] - 'A']);
                
            if(r-l+1 - maxi > k){
                f[s[l] -'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};