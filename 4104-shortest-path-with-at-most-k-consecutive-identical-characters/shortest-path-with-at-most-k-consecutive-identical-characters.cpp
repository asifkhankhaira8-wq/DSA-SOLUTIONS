class Solution {
    typedef long long ll;
const ll inf = LLONG_MAX / 4;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }
        vector<vector<ll>> dist(n, vector<ll>(k + 1, inf));
        priority_queue<
            tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [wt, node, cons] = pq.top();
            pq.pop();
            if (wt!=dist[node][cons]) continue;
            for (auto it : adj[node]) {
                int neigh = it.first;
                int w = it.second;
                int newCons = cons;

                if (labels[neigh] == labels[node]) {
                    newCons++;
                }
                else newCons=1;

                if (newCons <= k && wt + w < dist[neigh][newCons]) {
                    dist[neigh][newCons] = wt + w;
                    pq.push({wt + w, neigh, newCons});
                }
            }
        }
      ll ans = inf;
        for (int i = 1; i <= k; i++) ans = min(ans, dist[n - 1][i]);
        return ans == inf ? -1 : ans;
    }
};