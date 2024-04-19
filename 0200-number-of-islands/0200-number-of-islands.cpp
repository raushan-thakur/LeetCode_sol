class Solution {
public:
    void dfs(vector<vector<char>>& g, int i, int j, int n, int m){
        if(i<0 || i>n-1 || j<0 || j>m-1 || g[i][j] == '0') return;
        
        g[i][j] = '0';
        dfs(g, i+1, j, n, m);
        dfs(g, i-1, j, n, m);
        dfs(g, i, j+1, n, m);
        dfs(g, i, j-1, n, m);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};