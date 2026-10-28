class Solution {
public:
    int N,parent_val=0;
    vector<int>count,result;
    vector<vector<int>>adj;
    int dfsRoot(int node,int parent,int val){
        parent_val+=val;
        int x=1;
        for(int it:adj[node]){
            if(it==parent) continue;
            x+=dfsRoot(it,node,val+1);
        }
       return count[node]=x; 
    }
   void dfs(int node,int parent){
         for(int it:adj[node]){
            if(it==parent) continue;
            result[it]=result[node]-count[it]+(N-count[it]);
             dfs(it,node);
         }

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {  N=n;
      count.resize(n,0);
      result.resize(n,0);
        adj.resize(n,{});
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsRoot(0,-1,0);
        result[0]=parent_val;
        dfs(0,-1);
        
        return result;
    }
};