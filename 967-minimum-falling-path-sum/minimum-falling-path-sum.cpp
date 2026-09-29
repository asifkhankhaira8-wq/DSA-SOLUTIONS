class Solution {
public:
int fun(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
    int n=matrix.size();
      if(i<0) return 0;
      int left=1e9;
      int right=1e9;
      int bottom=1e9;
      int mini=1e9;
      if(dp[i][j]!=1e9) return dp[i][j];
      if(j==n){
        for(int k=0;k<n;k++){
         mini=min(mini,matrix[i][k]+fun(i-1,k,matrix,dp));
        }
      }
      else{
        bottom=matrix[i][j]+fun(i-1,j,matrix,dp);
        if(j>0) left=matrix[i][j-1]+fun(i-1,j-1,matrix,dp);
        if(j<n-1) right=matrix[i][j+1]+fun(i-1,j+1,matrix,dp);
      }
      mini=min(mini,min(left,min(right,bottom)));
      return dp[i][j]=mini;
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n+1,1e9));
        return fun(n-1,n,matrix,dp);
    }
};