class Solution {
public:
vector<vector<int>>adj;
vector<int>vis;
int ans=1;
  int dfs(int node,string &s){
     vis[node]=true;
     int first=0,second=0;
     for(int it:adj[node]){
          if(vis[it] || s[it]==s[node]) continue;
          int val=dfs(it,s);
          if (val>first) {
                second=first;
                first=val;
            }
            else if (val>second) {
                second = val;
            }
     }
     ans = max(ans, 1 + first + second);
        return 1 + first;
  }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vis.assign(n,0);
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,s);
        }
        return ans;
    }
};