class Solution {
public:
vector<vector<int>>adj;
pair<bool,int> fun(int node,int parent,vector<bool>& hasApple){
      int cnt=0;
      bool hA=hasApple[node];
      for(int it:adj[node]){
        if(it==parent) continue;

       auto [b,r]=fun(it,node,hasApple);
        hA=hA || b;
        if(b) cnt+=(2+r);
      }
      return {hA,cnt};
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n,{});
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        auto [b,ans]=fun(0,-1,hasApple);
        return ans;
    }
};