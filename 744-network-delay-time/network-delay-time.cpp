class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [w,node]=pq.top();
            pq.pop();

            for(auto it:adj[node]){
                if(w+it.second<dist[it.first]){
                    dist[it.first]=w+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dist[i]);
            if(dist[i]==1e9) return -1;
        }

        return maxi;
    }
};