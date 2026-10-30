class Solution {
public:
vector<vector<int>>ans;
vector<vector<int>>adj;
int target;
void fun(int node,vector<int>&temp){
      if(node==target){
        temp.push_back(node);
        ans.push_back(temp);
        temp.pop_back();
        return;
      }
      temp.push_back(node);
      for(int it:adj[node]){
        fun(it,temp);
      }
      temp.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>temp;
        int n=graph.size();
        adj.resize(n,{});
        target=n-1;
        for(int i=0;i<n;i++){
            for(int it:graph[i])  adj[i].push_back(it);
        }
       fun(0,temp);
       return ans;
        
    }
};