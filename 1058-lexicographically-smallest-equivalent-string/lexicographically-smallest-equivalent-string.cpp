class Solution {
public:
vector<vector<int>>val;
vector<vector<int>>adj;
vector<int>vis;
void dfs(int node,vector<int>&temp){
      vis[node]=true;
      temp.push_back(node);
      for(int it:adj[node]){
        if(!vis[it]) dfs(it,temp);
      }
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        adj.resize(26,{});
        vis.assign(26,0);
        for(int i=0;i<n;i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<26;i++){
            if(!vis[i] && !adj[i].empty()){
              vector<int>temp;
                dfs(i,temp);
                sort(temp.begin(),temp.end());
                val.push_back(temp);
            }
        }
      unordered_map<char,char>mp;
      for(auto it:val){
        char top=it[0]+'a';
        for(int ch:it){
            mp[ch+'a']=top;
        }
      }
      string ans="";
      for(char ch:baseStr){
        if(mp.find(ch)!=mp.end()) ans+=mp[ch];
        else ans+=ch;
      }
      return ans;
    }
};