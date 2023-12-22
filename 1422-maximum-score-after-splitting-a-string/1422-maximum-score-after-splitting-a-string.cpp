class Solution {
public:
    int findZero(string s, int n){
        int cnt =0;
        for(int i = 0; i<=n; i++){
            if(s[i] == '0') cnt++;
        }
        return cnt;
    }
    int findOne(string s, int n){
        int cnt =0;
        for(int i = n; i<s.length(); i++){
            if(s[i] == '1') cnt++;
        }
        return cnt;
    }
    int maxScore(string s) {
       int maxi = 0;
       int n = s.length();
        for(int i = 0; i<n-1; i++){
            int left = findZero(s,i);
            int right = findOne(s,i+1);
                
            maxi = max(maxi,left + right);
        }
        return maxi;
    }
};