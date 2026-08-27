class DisjointSet {
public:
    vector<int>parent,rank,size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;
         DisjointSet ds(n);
         int extraEdges=0;
         for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                extraEdges++;
            }
            else  ds.unionBySize(it[0],it[1]);
         }
       int components = 0;
        for (int i=0;i<n; i++) {
            if(ds.findUPar(i)==i)
                components++;
        }
        if(extraEdges>=components-1)
            return components-1;

        return -1;
    }
};