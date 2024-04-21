class Solution {
public:
    void dfs(int i, vector<vector<int>>&g, vector<int>& vis){
        if(vis[i]) return;
        
        vis[i] = true;
        
        for(auto it: g[i]){
            if(!vis[it])
                dfs(it, g,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int> > g(n);
        vector<int> vis(n,false);
        for(auto i: edges){
            int u = i[0], v = i[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs(source, g, vis);
        return vis[destination];
    }
};