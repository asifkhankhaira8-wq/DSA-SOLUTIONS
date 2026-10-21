class Solution {
public:
vector<vector<int>>subsets;
void generate(int i,int n,vector<int>& curr) {
    if (i == n){
        if(curr.empty()) return;
        subsets.push_back(curr);
        return;
    } 
    generate(i + 1,n,curr);
    curr.push_back(i);
    generate(i + 1,n,curr);
    curr.pop_back();
}
bool isConnected(vector<int>& nodes, vector<vector<int>>& adj) {
    int n = adj.size();
    int m = nodes.size();

    if (m <= 1) return true;

    vector<bool> selected(n, false), visited(n, false);

    for (int x : nodes) {
        selected[x] = true;
    }

    queue<int> q;
    q.push(nodes[0]);
    visited[nodes[0]] = true;

    int cnt = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (selected[v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
                cnt++;
            }
        }
    }

    return cnt == m;
}
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
      int n=nums.size();
      int cnt=0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
      vector<int>curr;
      generate(0,n,curr);
      for(int i=0;i<subsets.size();i++){
         int sum=0;
         if(subsets[i].size()==1) {
            if(nums[subsets[i][0]]==0) cnt++;
            continue;
         }
         for(int it:subsets[i]) sum+=nums[it];
         if(sum%2==0 && isConnected(subsets[i],adj)) cnt++;
         
      }
      return cnt;

    }
};