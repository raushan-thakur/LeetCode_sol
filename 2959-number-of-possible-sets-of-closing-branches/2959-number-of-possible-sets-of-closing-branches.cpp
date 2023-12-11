class Solution {
public:
    bool isWithinDistance(int mask, int n, vector<vector<int> > gr, int maxDistance){
        int dis =0;
        unordered_map<int, bool> taken;
        
        for(int i = 0; i<n ; i++){
            if(mask & (1<<i))
                taken[i]=true;
        }
        
        for(int k=0; k<n; k++)
            if(taken[k])
                 for(int i=0; i<n; i++)
                    if(taken[k])
                        for(int j=0; j<n; j++)
                            if(taken[k])
                                gr[i][j] = min(gr[i][j], (gr[i][k]+gr[k][j]));
                  
        
        for(int i = 0; i<n; i++)
            if(taken[i])
                for(int j =0; j<n; j++)
                    if(taken[j])
                        if(gr[i][j]> maxDistance)
                            return false;
            
        return true;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int> > gr(n, vector<int>(n, 1e4));
        
        for(int i = 0; i<n; i++)
            gr[i][i] = 0;
        
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            gr[u][v] = min(gr[u][v],w);
            gr[v][u] = min(gr[v][u],w);
        }
        
        int ans = 1;
        int ways = 1<<n;
        for(int i =1 ; i< ways ;i++){
            ans+= isWithinDistance(i, n, gr, maxDistance);
        }
        return ans;  
    }
};