class Solution {
public:
vector<vector<int>>dp;
bool fun(int i,int j,string s,string p){
    if(i<0 && j<0) return true;
     if(i<0) {
        if(p[j]!='*') return false;
          while(j>=0){
            if(p[j]=='*') j-=2;
            else break;
          }
          if(j<0) return true;
          return false;
        }
     if(j<0){
           return false;
     }
    if(dp[i][j]!=-1) return dp[i][j];
    int b=false;
    if(s[i]==p[j] || p[j]=='.'){
        b = fun(i-1,j-1,s,p);
    }
    else if(p[j]=='*'){
        for(int k=i;k>=0;k--){
            if(s[k]==p[j-1] ||  p[j-1]=='.'){
              b=b || fun(k-1,j-2,s,p);
            }
            else break;
        }
        b= b || fun(i,j-2,s,p);
    }
    return dp[i][j]=b;
}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,p);
    }
};