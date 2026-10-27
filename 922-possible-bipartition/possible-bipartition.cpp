class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for( const auto& it:dislikes){
               int u=it[0];
               int v=it[1];
               adj[u].push_back(v);
               adj[v].push_back(u);
        }
        vector<int>col(n+1,-1);
        queue<int>q;
       for(int i=1;i<=n;i++){ 
        if(col[i]!=-1) continue;
        q.push(i);
        col[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:adj[node]){
                if(col[it]==-1){
                    col[it]=1-col[node];
                    q.push(it);
                }
                else if(col[it]==col[node]) return false;
            }
        }
       }


        return true;
    }
};