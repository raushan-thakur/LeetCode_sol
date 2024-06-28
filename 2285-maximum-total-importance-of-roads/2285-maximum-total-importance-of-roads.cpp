class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
       vector<int>v(n ,0);
        for(auto it:roads){
            v[it[0]]++;
            v[it[1]]++;
        }
      long long  int ans =0;
        sort(v.begin() , v.end());
       long long int x = 1;
        for(auto it:v){
            ans += it*(x++);
        }
        return ans;
    }
};