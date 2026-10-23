class Solution {
public:
vector<vector<int>> adj;
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n==1) return {0};
    adj.assign(n, {});
    vector<int>indegree(n,0);
    for (auto it : edges) {
        int u=it[0];
        int v=it[1];
        indegree[u]++;
        indegree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

   queue<int>q;
   for(int i=0;i<n;i++){
    if(indegree[i]==1) q.push(i);
   }
  vector<int>ans;
   while(!q.empty()){
        ans.clear();
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it]==1){
                     q.push(it);
                }
            }
       }
   }
    return ans;
}

};
