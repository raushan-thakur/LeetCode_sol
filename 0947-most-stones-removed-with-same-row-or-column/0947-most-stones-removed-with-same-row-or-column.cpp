class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != -1) {
            parent[x] = find(parent, parent[x]);
            return parent[x];
        }
        return x;
    }

    void union_merge(vector<int>& parent, vector<int>& rank, int x, int y) {
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(20002, -1);
        vector<int> rank(20002, 0);

        for (auto s : stones) {
            int x = s[0];
            int y = s[1] + 10001;
            x = find(parent, x);
            y = find(parent, y);
            if (x != y) {
                union_merge(parent, rank, x, y);
            }
        }

        unordered_set<int> set;
        for (auto s : stones) {
            int x = s[0];
            x = find(parent, x);
            set.insert(x);
        }

        return n - set.size();
    }
};
