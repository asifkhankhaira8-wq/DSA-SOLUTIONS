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

         for(auto it:connections){
             ds.unionBySize(it[0],it[1]);
         }

        vector<int>parent=ds.parent;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(ds.findUPar(i));

        }
        return st.size()-1;
    }
};