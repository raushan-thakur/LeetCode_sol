class Solution {
public:
    bool checkValid(int n, int m, vector<vector<int>>& grid){
        vector<int> vis(10, 0);
        for(int i = n; i<n+3; i++){
            for(int j = m; j<m+3; j++){
                if(grid[i][j] >= 1 && grid[i][j] <= 9 && vis[grid[i][j]] != 1){
                    vis[grid[i][j]] = 1;
                }
                else return false;
            }
        }
        return true;
    }

    bool findSum(int n, int m, vector<vector<int>> &grid){
        vector<int> colSum(3, 0);
        vector<int> rowSum (3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                 rowSum[i] += grid[n + i][m + j];
                colSum[j] += grid[n + i][m + j];
            }
        }
        int diSum1 = grid[n][m] + grid[n + 1][m + 1] + grid[n + 2][m + 2];
        int diSum2 = grid[n][m + 2] + grid[n + 1][m + 1] + grid[n + 2][m];
        for(int i = 1; i<3; i++){
            if(colSum[i] != colSum[0] || rowSum[i] != rowSum[0]) return false;
        }
        return diSum1 == diSum2 && diSum1 == colSum[0];
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i = 0; i<=n-3; i++){
            for(int j = 0; j<=m-3; j++){
                if(checkValid(i, j, grid)){
                    if(findSum(i, j, grid)) cnt++;
                }
            }
        }
        return cnt;
    }
};