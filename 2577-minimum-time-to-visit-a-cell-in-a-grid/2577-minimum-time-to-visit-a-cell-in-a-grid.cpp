class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        vector<vector<int>>vis(m,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};
        vis[0][0] = 1;
        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == m-1 && col == n-1)return time;
            
            for(int i=0; i<4; i++){
                int nrow = row+dx[i];
                int ncol = col+dy[i];
                if(nrow>=0 && nrow <=m-1 && ncol>=0 && ncol<=n-1 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    if(grid[nrow][ncol]>time+1){
                        if((grid[nrow][ncol] - time)%2==0){
                            pq.push({grid[nrow][ncol]+1,{nrow,ncol}});
                        }
                        else{
                            pq.push({grid[nrow][ncol],{nrow,ncol}});
                        }
                    }
                    else{
                        pq.push({time+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};