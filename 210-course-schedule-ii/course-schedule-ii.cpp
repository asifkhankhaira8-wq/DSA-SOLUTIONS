class Solution {
public:
vector<int>ans;
bool dfs(int node, vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathVis)){
                return true;
            }}
            else if( pathVis[it]){
                   return true;
            }
    }
    ans.push_back(node);
    pathVis[node]=0;
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        const int n=numCourses;
      vector<int> pathVis(n,0);
       vector<int> vis(n,0);
        for(int i=0;i<numCourses;i++){
           if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)) return {};
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};