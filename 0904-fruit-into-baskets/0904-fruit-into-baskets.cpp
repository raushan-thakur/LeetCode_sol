class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size();
        int ans = 0;
        int l=0;
        int r=0;
        map<int,int> mp;
        
        while(r < n){
            mp[f[r]]++;
            if(mp.size() > 2){
                mp[f[l]]--;
                if(mp[f[l]] == 0){ 
                    mp.erase(f[l]);
                }
                l++;                
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;

    }
};