class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0;
        int l=0;
        int r=0;
        vector<int>hash(26,0);
        int maxLength = 0;
        
        while(r<s.length()){
            
            hash[s[r] -'A']++;
            maxLength = max(maxLength,  hash[s[r] -'A']);
            
            while((r-l+1)-maxLength>k){
                hash[s[l] -'A']--;
                maxLength=0;
                for(int i=0; i<26; i++) maxLength = max(maxLength, hash[i]);
                l++;
            }
            if((r-l+1)-maxLength<=k){
                ans= max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};