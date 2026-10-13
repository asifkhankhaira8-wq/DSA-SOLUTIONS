class Solution {
public:
    vector<long long> minTimeMaxPower(int n,vector<vector<int>>& edges,int power,vector<int>& cost,int source,int target) {
        if(source==target) return {0,power};
        if(cost[source]>power) return {-1,-1};

        vector<vector<pair<int,long long>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            long long w=edges[i][2];
            adj[u].push_back({v,w});
        }

        const long long INF=LLONG_MAX/4;
        vector<vector<long long>>dist(n,vector<long long>(power+1,INF));

        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>>pq;
        pq.push({0LL,source,power});
        dist[source][power]=0;

        while(!pq.empty()){
            auto [wt,node,p]=pq.top();
            pq.pop();

            if(cost[node]>p) continue;
            if(dist[node][p]<wt) continue;

            p-=cost[node];
            for(auto it:adj[node]){
                int neigh=it.first;
                long long w=wt+it.second;
                if(w<dist[neigh][p]){
                    dist[neigh][p]=w;
                    pq.push({w,neigh,p});
                }
            }
        }

        long long minTime=INF;
        long long maxPower=-1;
        for(int i=0;i<=power;i++){
            if(dist[target][i]<minTime){
                minTime=dist[target][i];
                maxPower=i;
            }
            else if(dist[target][i]==minTime&&minTime!=INF&&i>maxPower){
                maxPower=i;
            }
        }

        if(minTime==INF) return {-1,-1};
        return {minTime,maxPower};
    }
};
