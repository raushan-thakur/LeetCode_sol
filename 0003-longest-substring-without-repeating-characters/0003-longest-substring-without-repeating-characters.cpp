class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int hash[256] ={0};
            for(int j=i; j< n; j++){
                if(!hash[s[j]]){
                    hash[s[j]]++;
                    ans=max(ans, j-i+1);
                }else break;
            }
        }
        return ans;
    }
};