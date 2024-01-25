class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length();
        int m = t2.length();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
            int ans = 0;
            if(t1[i] == t2[j]){
                ans = 1 + next[j+1];
            }else{
                ans = max(next[j], curr[j+1]);
            }
            curr[j] = ans;
            }
            next = curr;
        }
        return curr[0];
    }
};