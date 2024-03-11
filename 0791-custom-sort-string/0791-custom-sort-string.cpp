class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> b(26,0);
         for(int i =0 ; i<s.size(); i++){
             b[s[i] - 'a']++;
         }
        string ans = "";
        for(int i =0 ; i<order.size(); i++) {
            while(b[order[i] - 'a']>0){
                ans+=order[i];
                b[order[i] - 'a']--;
            }
        }
        for(int i =0 ; i<26; i++){
            while(b[i]>0){
                ans+=i+'a';
                b[i]--;
            }            
        }
        return ans;
    }
};