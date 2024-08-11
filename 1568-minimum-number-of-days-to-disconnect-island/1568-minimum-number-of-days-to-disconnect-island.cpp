class Solution {
private:
    vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    int getisland(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int island = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0 || vis[i][j]==1)
                    continue;
                island++;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto pt = q.front();
                    q.pop();
                    for(int k = 0;k<4;k++){
                        int x = pt.first + dir[k].first;
                        int y = pt.second + dir[k].second;
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && vis[x][y]==0){
                            q.push({x,y});
                            vis[x][y] = 1;
                        }
                    }
                }
            }
        }
        return island;
    }
    
public:
    int minDays(vector<vector<int>>& grid) {
        int island = getisland(grid);
        if(island<1 || island>1)
            return 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    island = getisland(grid);
                    if(island<1 || island>1)
                        return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};