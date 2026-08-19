class Solution {
public:
bool fun(string &s,string &w){
    int n=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=w[i]){
            n++;
        }
        if(n>1){
            return false;
        }
    }
    return n==1;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         bool b=false;
         bool c=false;
        int n=wordList.size();
        unordered_map<string,bool> vis;
        for(int i=0;i<n;i++){
            if(endWord==wordList[i]) c=true;
            if(beginWord==wordList[i]){
               b=true;
            }
           vis[wordList[i]]=false;
        }
        if(!c) return 0;
        if(!b)  {n++;
            wordList.push_back(beginWord);}
        
        vis[beginWord]=false;
        
        unordered_map<string, vector<string>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(fun(wordList[i],wordList[j])){
                  adj[wordList[i]].push_back(wordList[j]);
                  adj[wordList[j]].push_back(wordList[i]);
               }
            }}

        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=true;
         int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int i=0;i<sz;i++){
              string top=q.front();
              q.pop();
              if(top==endWord) return ans;
              for(string it:adj[top]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);}
              }
            }
        }
        return 0;
        
    }
};