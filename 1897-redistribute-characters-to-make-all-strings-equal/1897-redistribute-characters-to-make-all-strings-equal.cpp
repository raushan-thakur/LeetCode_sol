class Solution {
public:
    bool makeEqual(vector<string>& words) {

        int n = words.size();
        if(n==1) return true;
        vector<int> a(26,0);
        
        for(int i= 0; i<n; i++){
            for(int j= 0; j<words[i].size(); j++){
                int ch = words[i][j] - 'a';
                a[ch]++;
            }
        }
        
        for(int i= 0; i<26; i++){
                if(a[i] % n) return false;
        }
        return true;
    }
};