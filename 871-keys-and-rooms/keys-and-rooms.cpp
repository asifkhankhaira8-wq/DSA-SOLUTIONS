class Solution {
public:
 vector<int>vis;
void dfs(int node,vector<vector<int>>& adj){
      vis[node]=true;
      for(int it:adj[node]){
        if(!vis[it]) dfs(it,adj);
      }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vis.assign(n,0);
        dfs(0,rooms);
       for(int it:vis) if(!it) return false;
       return true;
    }
};