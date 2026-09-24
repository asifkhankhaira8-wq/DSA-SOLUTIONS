class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    int src,dst;
    typedef long long ll; 
    const long long INF=1e18;
    bool fun(int mid, int k ){
        int n = adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    vector<int>dist(n,1e9);
    dist[src]=0;
    while(!pq.empty()){
        auto [cost,node]=pq.top();
        pq.pop();
       
        if(node==dst) return dist[node]<=k;
        if(cost>dist[node])continue;

        for(auto &e : adj[node]) {
                int v = e.first, w = e.second;
                int cost = w > mid ? 1 : 0;
                if(dist[node] + cost < dist[v]) {
                    dist[v] = dist[node] + cost;
                    pq.push({dist[v], v});
                }
            }
    }
    return false;
}
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        adj.resize(n+1);
        src=source;
        dst=target;
        int maxi = 0;
        for(int i=0;i<edges.size();i++){
              int u=edges[i][0];
              int v=edges[i][1];
              int w=edges[i][2];

              adj[u].push_back({v,w});
              adj[v].push_back({u,w});
              maxi=max(maxi,w);
        }
        int low=0;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(fun(mid,k)){
                ans=mid;
              high=mid-1;
            }
            else low = mid+1;
            

        }
        return ans;
    }
};