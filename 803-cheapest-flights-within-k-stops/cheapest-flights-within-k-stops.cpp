class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }

        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
             auto it=q.front();
             q.pop();
            int w=it.first;
            int node=it.second.first;
            int key=it.second.second;

            if(key>k) continue;
            for(auto neigh:adj[node]){
                if(w+neigh.second<dist[neigh.first]){
                    dist[neigh.first]=w+neigh.second;
                    q.push({dist[neigh.first],{neigh.first,key+1}});
                }
            }

        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};