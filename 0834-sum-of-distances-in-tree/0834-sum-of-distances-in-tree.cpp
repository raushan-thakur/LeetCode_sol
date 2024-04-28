class Solution {
public:
    vector<int> sum,ans,fans;
    vector<vector<int>> graph;
    void dfs1(int i,int a){
        int s=0,c=0;
        if(i!=-1 && graph[a].size()==1){
            sum[a]=s;
            return;
        }
        for(auto b:graph[a])  {
            if(b!=i){
                dfs1(a,b);
                s+=sum[b]+1;
                c+=ans[b]+sum[b]+1;
            }
        }
        sum[a]=s;
        ans[a]=c;
    }
    void dfs2(int i,int a)  {
        if(i==-1)
            fans[a]=ans[a];
        else
            fans[a]=fans[i]-2*sum[a]-2+graph.size();
         for(auto b:graph[a]){
             if(i!=b) {
                 dfs2(a,b);
             }
         }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& a) {
       graph= vector<vector<int>>(n);
        sum=vector<int>(n,0);
         ans=vector<int>(n,0);
        fans=vector<int>(n,0);
        for(int i=0;i<n-1;i++)
        {
            graph[a[i][0]].push_back(a[i][1]);
            graph[a[i][1]].push_back(a[i][0]);
        }
        dfs1(-1,0);
        dfs2(-1,0);  
        return fans;
    }
};