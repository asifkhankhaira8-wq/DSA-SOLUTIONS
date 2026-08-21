class Solution {
public:
bool bfs(int color,int node , vector<pair<int,int>>&vis,vector<vector<int>>& graph){
    vis[node].first=true;
    vis[node].second=color;
    for(int it:graph[node]){
        if(!vis[it].first){
           if(!bfs(!color,it,vis,graph)){
            return false;
           }
        }
        else{
            if(vis[it].second==color){
                return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
   vector<pair<int,int>> vis(n,{0,0});
   for(int i=0;i<n;i++){
           if(!vis[i].first){
            if(!bfs(0,i,vis,graph)) return false;
           }
        }
   return true;
        
    }
};