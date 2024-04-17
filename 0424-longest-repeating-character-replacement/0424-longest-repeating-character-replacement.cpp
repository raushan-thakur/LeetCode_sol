class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int maxi = 0;
            vector<int> f(26,0);
            for(int j=i; j<n; j++){
                f[s[j] - 'A']++;
                maxi = max(maxi, f[s[j] - 'A']);
                
                if(j-i+1 - maxi <= k){
                    ans = max(ans, j-i+1);
                }else break;
            }
        }
        return ans;
    }
};