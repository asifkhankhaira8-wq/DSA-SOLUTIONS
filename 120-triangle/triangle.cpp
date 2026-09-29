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
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            int sz=triangle[i].size();
            for(int j=0;j<sz;j++){
                 int lt=1e9;
                 int up=1e9;
                 if(j<sz-1) up=triangle[i][j]+dp[i-1][j];
                 if(j>0) lt=triangle[i][j]+dp[i-1][j-1];
                dp[i][j]=min(lt,up);
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};