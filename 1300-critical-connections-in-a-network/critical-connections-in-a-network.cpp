class Solution {
public:
    vector<vector<int>> bridges;
    vector<int> tin, low;
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto adjNode : adj[node]) {
            if (adjNode == parent) continue;

            if (!vis[adjNode]) {
                dfs(adjNode, node, adj, vis);

                low[node] = min(low[node], low[adjNode]);
                if (low[adjNode] > tin[node]) {
                    bridges.push_back({node, adjNode});
                }
            } else {
                low[node] = min(low[node], tin[adjNode]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        tin.resize(n);
        low.resize(n);

        dfs(0, -1, adj, vis);

        return bridges;
    }
};