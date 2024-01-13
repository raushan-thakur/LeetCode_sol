class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> scnt(26,0);
        for(int i = 0; i<s.length(); i++){
            scnt[s[i]-'a']++;
        }
        for(int i = 0; i<s.length(); i++){
            scnt[t[i]-'a']--;
        }
        
        int cnt = 0;
        for(int i =0; i<26; i++){
            if(scnt[i]>0) cnt+=scnt[i];
        }
        return cnt;
    }
};