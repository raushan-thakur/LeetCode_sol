class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n =0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1') n++;
        }
        
        string ans = "";
        for(int i=0; i<n-1; i++){
            ans+="1";
        }
        
        int x = s.length() - n;
        for(int i=0; i<x; i++){
            ans+="0";
        }
        ans+="1";
        
        return ans;
    }
};