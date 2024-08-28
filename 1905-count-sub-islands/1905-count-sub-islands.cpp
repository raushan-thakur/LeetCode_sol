class Solution {
public:
    void dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i,int j,int &flag){
       if(i<0 or j<0 or i>=g2.size() or j>=g2[0].size() or g2[i][j]==0) return;
        if(g1[i][j]==0) flag=0;
        
        g2[i][j]=0;
        
        dfs(g1,g2,i+1,j,flag);
        dfs(g1,g2,i-1,j,flag);
        dfs(g1,g2,i,j+1,flag);
        dfs(g1,g2,i,j-1,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    int flag=1;
                    dfs(grid1,grid2,i,j,flag);
                    ct+=flag;
                }
            }
        }
        return ct;
    }
};