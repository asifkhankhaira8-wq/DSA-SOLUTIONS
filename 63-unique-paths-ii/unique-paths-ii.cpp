class Solution {
public:
int fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
    if(i==0 && j==0 ) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int left=0;
    int right=0;
    if(j>0 && !obstacleGrid[i][j-1]) left=fun(i,j-1,dp,obstacleGrid);
    if(i>0 && !obstacleGrid[i-1][j]) right=fun(i-1,j,dp,obstacleGrid);
    return dp[i][j]=left+right;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0]) return 0;
       vector<vector<int>>dp(m,vector<int>(n,-1));
       return fun(m-1,n-1,dp,obstacleGrid);
    }
};