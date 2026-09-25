class Solution {
public:
    typedef long long ll;

    struct Edge {
        int to;
        ll cost;
        ll taxi;
    };
    vector<vector<Edge>> adj;
    const ll INF = 1e18;
    vector<ll> dijkstraEmpty(int src, int n) {
        priority_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
        vector<ll> dist(n, INF);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d != dist[node])
                continue;
            for (auto it : adj[node]) {
                int neigh = it.to;
                ll wt = it.cost;
                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist;
    }

    vector<ll> dijkstraWithApple(int src, int n) {
        priority_queue<
            pair<ll, int>,
            vector<pair<ll, int>>,
            greater<pair<ll, int>>
        > pq;
        vector<ll> dist(n, INF);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d != dist[node])
                continue;
            for (auto it : adj[node]) {
                int neigh = it.to;
                ll wt = it.cost * it.taxi;
                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist;
    }
    vector<int> minCost( int n,vector<int>& prices, vector<vector<int>>& roads
    ) {
         adj.resize(n);
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            ll cost = road[2];
            ll taxi = road[3];
            adj[u].push_back({v, cost, taxi});
            adj[v].push_back({u, cost, taxi});
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            vector<ll> emptyDist = dijkstraEmpty(i, n);
            vector<ll> appleDist = dijkstraWithApple(i, n);
            ll best = prices[i];
            for (int j = 0; j < n; j++) {
                if (emptyDist[j] == INF || appleDist[j] == INF)
                    continue;
                ll total = emptyDist[j]+ prices[j]+ appleDist[j];
                best = min(best, total);
            }
            ans[i] = best;
        }
        return ans;
    }
};