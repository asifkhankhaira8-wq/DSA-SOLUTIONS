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

        vector<vector<int>> dist(n, vector<int>(k+2, 1e9));
        dist[src][0]=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{src,0}});
    
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int w=it.first;
            int node=it.second.first;
            int d=it.second.second;

            if(node == dst){
                return w;
            }

            if(d>k) continue;
            for(auto neigh:adj[node]){
                if(w+neigh.second<dist[neigh.first][d+1]){
                    dist[neigh.first][d+1]=w+neigh.second;
                    pq.push({dist[neigh.first][d+1],{neigh.first,d+1}});
                }
            }

        }
        return  -1 ;
    }
};