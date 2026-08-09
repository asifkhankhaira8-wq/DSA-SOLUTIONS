class Solution {
public:
int getHeight(int node, vector<vector<int>> &adj){
           int maxi=1;
        for(auto neigh:adj[node]){
            int height=getHeight(neigh,adj);
            maxi=max(maxi,height+1);
        }
        return maxi;
}
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
           adj[parent[i]].push_back(i);
        }
        int height=getHeight(0,adj);
        int depth=0;
        queue<int>q;
        q.push(0);
        long long ans=0;
        while(!q.empty()){
            int size=q.size();
            depth++;
           for(int i=0;i<size;i++){ 
               int top=q.front();
               q.pop();
              ans+=(1LL*nums[top]*(height-depth+1));
             for(int it:adj[top]){
                q.push(it);
             }
           }
        }
        return ans;
    }
};