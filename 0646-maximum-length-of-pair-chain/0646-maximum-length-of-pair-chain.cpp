class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b ){
        return a[1]< b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int ans= 1;
        int l =0, r=0;
        while(r<pairs.size()){
            if(pairs[r][0]> pairs[l][1]){
                ans++;
                l=r;
            }
            r++;
        }
         return ans;
    }
   
};