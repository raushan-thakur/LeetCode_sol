class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int n =edges.size()+1;
        vector<int>count(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            count[a]++;
            count[b]++;
            if(count[a]==edges.size())
            {
                return a;
            }
            if(count[b]==edges.size())
            {
                return b;
            }
        }
        return -1;
    }
};
