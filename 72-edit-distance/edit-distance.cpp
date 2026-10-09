class Solution {
public:
int fun(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(dp[i][j]!=-1) return dp[i][j];
    int same=1e9;
    int notSame=1e9;
    if(word1[i]==word2[j]) same=fun(i-1,j-1,word1,word2,dp);
    else{
        notSame=min(notSame,1+fun(i,j-1,word1,word2,dp));
        notSame=min(notSame,1+fun(i-1,j-1,word1,word2,dp));
        notSame=min(notSame,1+fun(i-1,j,word1,word2,dp));
    }
    return dp[i][j]=min(same,notSame);
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,1e9));
      //  return fun(n-1,m-1,word1,word2,dp);
      for(int i=0;i<=m;i++) dp[0][i]=i;
      for(int j=0;j<=n;j++) dp[j][0]=j;
      
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
    if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
    else{
        dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
        dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
        dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
    }
        }
      }
      return dp[n][m];

    }
};