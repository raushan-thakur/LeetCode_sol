class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& newI) {
       vector<vector<int>>ans;
       int n=inv.size();
        int i=0;
       while(i<n and inv[i][1]<newI[0]){
           ans.push_back(inv[i++]);
       }

       while(i<n and newI[1]>=inv[i][0]){
           newI[0]=min(newI[0],inv[i][0]);
           newI[1]=max(newI[1],inv[i][1]);
           i++;
       }
       ans.push_back(newI);
      while(i<n ){
          ans.push_back(inv[i++]);
      }
       return ans; 
    }
};