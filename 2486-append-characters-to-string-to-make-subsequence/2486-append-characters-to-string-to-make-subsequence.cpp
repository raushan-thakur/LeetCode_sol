class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0, r=0;
        
        while(l<s.length() && r<t.length()){
            if(s[l] == t[r]){
                r++;
            }
            l++;
        }
        return t.length()-r;
    }
};