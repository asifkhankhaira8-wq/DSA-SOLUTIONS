class DisjointSet {
    vector<int>parent,rank,size;
public:
    DisjointSet(int n) {
     rank.resize(n+1,0);
     size.resize(n+1,1);
     parent.resize(n+1);

     for(int i=0;i<=n;i++){
        parent[i]=i;
     }
    }
    int findUPar(int u){
        if(u==parent[u]) {
            return u;
        }
        return parent[u]=findUPar(parent[u]);
    }
    bool find(int u, int v) {
        return findUPar(u)==findUPar(v);
    }
    void unionByRank(int u, int v) {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v) {
         int ulp_u=findUPar(u);
         int ulp_v=findUPar(v);
         if(ulp_u==ulp_v) return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

       
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=i+1;j<n;j++){
                if(stones[j][0]==x || stones[j][1]==y){
                ds.unionBySize(i,j);
            }}
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                components++;
            }
        }
        return n-components;
        
    }
};