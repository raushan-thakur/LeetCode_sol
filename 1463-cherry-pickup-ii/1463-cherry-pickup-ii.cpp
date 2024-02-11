class Solution {
public:
    vector<vector<vector<int>>> memo;
    int solve(vector<vector<int>>& grid, int r, int a, int b){
        
        if(a < 0 || b < 0 || a >= grid[0].size() || b >= grid[0].size()) return 0;
        
        if(r == grid.size()) return 0;
        
        if(memo[r][a][b] != -1)
            return memo[r][a][b];
        
        int res = 0;
        res += grid[r][a];
        res += grid[r][b];
        
        int mx = 0;
        for(int x = a - 1; x <= a + 1; x++) {
            for(int y = b - 1; y <= b + 1; y++) {
                if(x < y) { 
                    mx = max(mx, solve(grid, r + 1, x, y));
                }
            }
        }
        
        res += mx;
        return memo[r][a][b] = res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        memo.resize(rows + 1, vector<vector<int>>(cols + 1, vector<int>(cols + 1, -1)));
        return solve(grid, 0, 0, cols - 1);
    }
};
