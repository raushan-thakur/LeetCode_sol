class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count=0;
        
        vector<int>a(3,-1);
        
        for(int i=0; i<n; i++){
            a[s[i] - 'a'] = i;
            count+=1+min(a[0], min(a[1], a[2]));
        }    
            
        return count;
    }
};