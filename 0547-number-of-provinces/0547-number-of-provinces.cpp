class Solution {
    private:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int i){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(vis[it] == 0)
            dfs(adj, vis, it);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        
        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int cnt=0;
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(adj, vis, i);
            }
        }
        return cnt;
    }
};