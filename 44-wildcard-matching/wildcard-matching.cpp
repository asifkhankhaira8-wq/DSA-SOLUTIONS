class Solution {
int fun(int i,int j,string &s,string &p,vector<vector<int>>&dp){
    if(i<0){
      while(j>=0 && p[j]=='*'){
          j--;
      }
       if(j<0) return true;
       return false;
    } 
   
    if(i>=0 && j<0) return false;
    if(dp[i][j]!=-1) return dp[i][j];
   
    if(s[i]==p[j] || p[j]=='?') dp[i][j]=fun(i-1,j-1,s,p,dp);
    else if(p[j]!='*') dp[i][j]=false;
    else{
        int mini=false ;
        for(int k=i+1;k>=0;k--){
            mini=mini || fun(k-1,j-1,s,p,dp);
        }
        dp[i][j]=mini;
    }
return dp[i][j];   
}
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,p,dp);
    }
};