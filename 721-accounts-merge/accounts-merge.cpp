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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
       for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mp.find(mail)==mp.end()){
                mp[mail]=i;
            }
            else {
                ds.unionBySize(i,mp[mail]);     
            }
        }
       }
        vector<vector<string>>elements(n);
        for(auto it:mp){
            elements[ds.findUPar(it.second)].push_back(it.first);
        }
    
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
           if(elements[i].size()==0) continue;
           sort(elements[i].begin(),elements[i].end());
           vector<string>temp;
           temp.push_back(accounts[i][0]);
         for(auto it:elements[i]){
            temp.push_back(it);
         }
        ans.push_back(temp);
       }
       return ans;
        
    }
};