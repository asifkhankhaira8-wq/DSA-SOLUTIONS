class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])  return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByMin(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (ulp_u < ulp_v) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
          int n=s1.size();
           DisjointSet ds(26);
          for(int i=0;i<n;i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            ds.unionByMin(u,v);
          }
          string ans="";
          for(char ch:baseStr){
            ans+=char(ds.findUPar(ch-'a')+'a');
          }
        return ans;
    }
};