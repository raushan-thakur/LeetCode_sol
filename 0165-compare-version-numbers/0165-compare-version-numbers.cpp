class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i=0, j=0;
        
        while(i<n || j<m){
            int val1 = 0, val2 = 0;
            
            while(i<n && version1[i] != '.'){
                val1 = val1*10 + (version1[i] - '0');
                i++;
            }
            i++;
            while(j<m && version2[j] != '.'){
                val2 = val2*10 + (version2[j] - '0');
                j++;
            }
            j++;
            
            if(val1 > val2) return 1;
            else if(val2 > val1) return -1;
        }
        return 0;
    }
};