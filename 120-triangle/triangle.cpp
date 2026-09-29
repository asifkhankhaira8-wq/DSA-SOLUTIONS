class Solution {
public:
int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
      if(i<0) return 0;
      if(dp[i][j]!=1e9) return dp[i][j];
      int lt=1e9;
      int up=1e9;
      int n=triangle[i].size();
      if(j<n) up=triangle[i][j]+fun(i-1,j,triangle,dp);
      if(j>0) lt=triangle[i][j-1]+fun(i-1,j-1,triangle,dp);

      return dp[i][j]=min(lt,up);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        int mini=1e9;
        for(int i=0;i<triangle[n-1].size();i++){
            mini=min(mini,triangle[n-1][i]+fun(n-2,i,triangle,dp));
        }
        return mini;
    }
};