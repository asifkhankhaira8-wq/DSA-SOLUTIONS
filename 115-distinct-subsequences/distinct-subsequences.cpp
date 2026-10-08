class Solution {
public:
int fun(int i,int j,string &s ,string &t, vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int take=0;
    if(s[i]==t[j]) take=fun(i-1,j-1,s,t,dp);
    int notTake=fun(i-1,j,s,t,dp);
    return dp[i][j]=take+notTake;
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
      vector<vector<unsigned long long>>dp(n+1,vector<unsigned  long long>(m+1,0));
      for(int i=0;i<=n;i++) dp[i][0]=1;
      //return fun(n-1,m-1,s,t,dp);
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            unsigned long long take=0;
            if(s[i-1]==t[j-1]) take=dp[i-1][j-1];
          unsigned  long long notTake=dp[i-1][j];
             dp[i][j]=take+notTake;
        }
      }
      return dp[n][m];
    }
};