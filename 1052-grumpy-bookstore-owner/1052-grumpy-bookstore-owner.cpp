class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int ans =0;
        for(int i=0; i<g.size(); i++){
            if(g[i] == 0){
                ans+=c[i];
                c[i] = 0;
            }
        }
        
        int maxi = 0;
        for(int i=0; i<m; i++){
            maxi+=c[i];
        }
        int curr = maxi;
        for(int i=m; i<c.size(); i++){
            curr-=c[i-m];
            curr+=c[i];
            maxi = max(maxi, curr);
        }
        
        return ans+maxi;
    }
};