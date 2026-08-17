class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
    if(vis[node]) return ;
    vis[node]=true;
    for(int it:adj[node]){
        dfs(it,adj,vis);
    }
    return ;
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
               adj[i].push_back(j);
               adj[j].push_back(i);
            }
        }}
        int cnt=0;
        vector<int>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};