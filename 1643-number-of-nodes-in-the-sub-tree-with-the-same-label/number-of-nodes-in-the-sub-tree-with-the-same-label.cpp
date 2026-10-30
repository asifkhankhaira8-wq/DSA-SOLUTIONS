class Solution {
public:
vector<int>result;
vector<vector<int>>adj;
vector<int> dfs(int node ,int parent,string &labels){
        vector<int>f(26,0);
        for(int it:adj[node]){
            if(it==parent) continue;
            vector<int>frequency=dfs(it,node,labels);
            for(int i=0;i<26;i++){
                f[i]+=frequency[i];
            }
        }
        f[labels[node]-'a']++;
        result[node]=f[labels[node]-'a'];
        return f;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n,{});
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        result.assign(n,0);
        dfs(0,-1,labels);
        return result;
    }
};