class Solution {
public:
    int dx[9]={1,1,1,0,0,0,-1,-1,-1};
    int dy[9]={1,-1,0,1,-1,0,1,-1,0};
bool valid(int x,int y, int n){
   return x>=0 && y>=0 && x<n && y<n;
}
int fun(int row,int i,int j,vector<vector<int>>& grid ,vector<vector<vector<int>>>&dp){
        int m=grid[0].size();
    if(row==0) {
        for(int k=0;k<9;k++){
         int ni=i+dx[k];
         int nj=j+dy[k];
         if(ni==0 && nj==m-1) {
            return grid[0][ni]+grid[0][nj];
         }
    }
         return -1e9;
    }
    if(dp[row][i][j]!=-1)  return dp[row][i][j];
   int maxi=INT_MIN;
    for(int k=0;k<9;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(valid(ni,nj,m)){
            if(ni==nj) maxi=max(maxi,grid[row][nj]+fun(row-1,ni,nj,grid,dp));
            else maxi=max(maxi,grid[row][ni]+grid[row][nj]+fun(row-1,ni,nj,grid,dp));
        }
    }
    return dp[row][i][j]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       /*int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) maxi=max(maxi,grid[n-1][j]+fun(n-2,i,j,grid,dp));
                else maxi=max(maxi,grid[n-1][i]+grid[n-1][j]+fun(n-2,i,j,grid,dp));
        }
        }*/
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m, -1e9)));

        dp[0][0][m-1]=grid[0][0]+grid[0][m-1];
        for(int row=1;row<n;row++){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                   int maxi=INT_MIN;
    for(int k=0;k<9;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
           if(valid(ni,nj,m)){
             if(i==j) maxi=max(maxi,grid[row][j]+dp[row-1][ni][nj]);
             else maxi=max(maxi,grid[row][i]+grid[row][j]+dp[row-1][ni][nj]);
             }
            }
       dp[row][i][j]=maxi;
                }
            }
        }
       int maxi=-1e9;
       for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          maxi=max(maxi,dp[n-1][i][j]);
       }
       }
       return maxi;
    }
};