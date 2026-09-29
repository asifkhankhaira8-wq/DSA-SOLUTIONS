class Solution {
public:
int fun(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0 ) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=0;
    int right=0;
    if(j>0) left=fun(i,j-1,dp);
    if(i>0) right=fun(i-1,j,dp);
    return dp[i][j]=left+right;

}
    int uniquePaths(int m, int n) {
    //  vector<vector<int>>dp(m,vector<int>(n,0));
     // return fun(m-1,n-1,dp);
     vector<int>prev(n,1);
     for(int i=1;i<m;i++){
        vector<int>curr(n,0);
        for(int j=0;j<n;j++){
          int left=0;
          int right=0;
          if(j>0) left=curr[j-1];
          if(i>0) right=prev[j];
         curr[j]=left+right;
        }
        prev=curr;
     }
     return prev[n-1];
        
    }
};