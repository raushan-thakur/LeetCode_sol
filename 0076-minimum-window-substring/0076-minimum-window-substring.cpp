class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int n = s.length();
        int m = t.length();
        int sIndex =-1;
        
        for(int i=0; i<m; i++){
            mp[t[i]]++;
        }
        
        int l=0, r=0, ans=INT_MAX, cnt=0;
        
        while(r<n){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;
            while(cnt == m){
                if(r-l+1 < ans){
                    ans = min(ans, r-l+1);
                    sIndex = l;
                }
                
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "": s.substr(sIndex, ans);
    }
};