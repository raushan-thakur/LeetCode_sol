class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n==1) return {0};
        
        vector<int> deg(n,0);
        vector<vector<int>> gr(n);
        for(auto it: edges){
            deg[it[0]]++;
            deg[it[1]]++;
            
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i] == 1) q.push(i);
        }
        
        while(n>2){
            int sz = q.size();
            n-=sz;
            for(int i=0; i<sz; i++){
                int front = q.front();
                q.pop();
                
                for(auto it : gr[front]){
                    deg[it]--;
                    if(deg[it] == 1){
                        q.push(it);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};