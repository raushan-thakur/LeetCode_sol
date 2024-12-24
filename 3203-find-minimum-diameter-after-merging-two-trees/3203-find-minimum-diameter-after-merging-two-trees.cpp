class Solution
{
public:
    void dfs(int node, int parent, vector<vector<int>>& adj, int& maxDist, int& farthestNode, int dist) {
        if (dist > maxDist) {
            maxDist = dist;
            farthestNode = node;
        }
        
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, adj, maxDist, farthestNode, dist + 1);
            }
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &nums1, vector<vector<int>> &nums2){
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> adj1(n + 1);
        vector<vector<int>> adj2(m + 1);
        for (auto &it : nums1){
            adj1[it[1]].push_back(it[0]);
            adj1[it[0]].push_back(it[1]);
        }
        for (auto &it : nums2){

            adj2[it[1]].push_back(it[0]);
            adj2[it[0]].push_back(it[1]);
        }

        int maxDist1 = 0;
        int farthestNode1 = 0;
        
        dfs(0, -1, adj1, maxDist1, farthestNode1, 0);
        maxDist1 = 0;
        dfs(farthestNode1, -1, adj1, maxDist1, farthestNode1, 0);

        int diameter1 = maxDist1;

        int maxDist2 = 0;
        int farthestNode2 = 0;
        
        dfs(0, -1, adj2, maxDist2, farthestNode2, 0);
        maxDist2 = 0;
        dfs(farthestNode2, -1, adj2, maxDist2, farthestNode2, 0);
        int diameter2 = maxDist2;

        
        return max({(diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1, diameter1, diameter2});
    }
};