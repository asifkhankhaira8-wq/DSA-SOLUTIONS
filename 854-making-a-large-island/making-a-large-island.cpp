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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n + 1);
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]==0) continue;
                 for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]){
                        int node = x*n+y;
                        int neigh=nx*n + ny;
                        ds.unionBySize(node,neigh);
                    }
                 }
            }
        }
        int maxi=-1e9;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]==1) continue;
                
               set<int> st;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1){
                        int adjNode = nx * n + ny;
                        st.insert(ds.findUPar(adjNode));
                        
                    }
                 }
                 int cnt = 1;
                    for (auto parent : st) {
                        cnt += ds.size[parent];
                    }
                 maxi=max(cnt,maxi);
            }
        }
   if(maxi==-1e9) return n*n;
   return maxi;
        
        
    }
};