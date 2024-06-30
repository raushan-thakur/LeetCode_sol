class DSU {
public:
    int numberOfNodes;
    int *parent;
    int *rank;
    int components;

    DSU(int numberOfNodes) : numberOfNodes(numberOfNodes), components(numberOfNodes) {
        parent = new int[numberOfNodes + 1];
        rank = new int[numberOfNodes + 1];
        for (int i = 1; i <= numberOfNodes; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~DSU() {
        delete[] parent;
        delete[] rank;
    }

    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void join(int node1, int node2) {
        int root1 = findParent(node1);
        int root2 = findParent(node2);

        if (root1 != root2) {
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
            components -= 1;
        }
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n);
        DSU dsuBob(n);

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0];
        });

        int edgesUsed = 0;

        for(const vector<int> &edge: edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            int f = false;

            if(type == 3 && dsuAlice.findParent(u) != dsuAlice.findParent(v)) {
                dsuAlice.join(u, v);
                f = true;
            }

            if(type == 3 && dsuBob.findParent(u) != dsuBob.findParent(v)) {
                dsuBob.join(u, v);
                f = true;
            }

            if(type == 1 && dsuAlice.findParent(u) != dsuAlice.findParent(v)) {
                dsuAlice.join(u, v);
                f = true;
            }

            if(type == 2 && dsuBob.findParent(u) != dsuBob.findParent(v)) {
                dsuBob.join(u, v);
                f = true;
            }

            if(f) {
                edgesUsed += 1;
            }
        }

        if(dsuAlice.components != 1 || dsuBob.components != 1) {
            return -1;
        }
        return edges.size() - edgesUsed;

    }
};
