class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) {
        
        vector<vector<pair<int, int> > > v(n);
        for(auto m: meet){
            v[m[0]].push_back({m[1], m[2]});
            v[m[1]].push_back({m[0], m[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int> > >pq;
        
        pq.push({0,0});
        pq.push({0,firstPerson});
        vector<int> vis(n,0);
        
        while(!pq.empty()){
            auto[t,y] = pq.top();
            pq.pop();
            
            if(vis[y]) continue;
            vis[y] =1;
            for(auto it: v[y]){
                if(vis[it.first]) continue;
                if(it.second>=t) pq.push({it.second, it.first});
            }
        }
        
        vector<int>a;
        for(int i=0; i<n; i++){
            if(vis[i]) a.push_back(i);
        }
        
        return a;
    }
};