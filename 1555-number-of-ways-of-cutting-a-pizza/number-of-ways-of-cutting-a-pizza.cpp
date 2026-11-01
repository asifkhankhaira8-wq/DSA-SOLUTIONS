class Solution {
public:
int n,m;
int MOD=1e9+7;
vector<string> pizza;
vector<vector<long long>>prefix;
vector<vector<vector<long long>>>dp;
int fun(int i,int j,int k){
   if(k == 0) {
    return prefix[n][m] - prefix[i][m]
           - prefix[n][j] + prefix[i][j]>0;
}

   if(dp[i][j][k]!=-1) return dp[i][j][k];
   long long ways=0;
    // cutting horizontally;
    for(int x=i;x<n-1;x++){
        int row2=x+1,col2=m,row1=i+1,col1=j+1;
        int up=prefix[row2][col2]-prefix[row2][col1-1]-prefix[row1-1][col2]+prefix[row1-1][col1-1];
        row1=x+2,col1=j+1,row2=n,col2=m;
        int down=prefix[row2][col2]-prefix[row2][col1-1]-prefix[row1-1][col2]+prefix[row1-1][col1-1];
        if(up>0 && down>0){
            ways=(ways+fun(x+1,j,k-1))%MOD;
        }
    }
    //cutting vertically;
     for(int x=j;x<m-1;x++){
         int row2=n,col2=m,row1=i+1,col1=x+2;
        int right=prefix[row2][col2]-prefix[row2][col1-1]-prefix[row1-1][col2]+prefix[row1-1][col1-1];
        row2=n,col2=x+1,row1=i+1,col1=j+1;
        int left=prefix[row2][col2]-prefix[row2][col1-1]-prefix[row1-1][col2]+prefix[row1-1][col1-1];
        if(right>0 && left>0){
            ways=(ways+fun(i,x+1,k-1))%MOD;
        }
    }
    return dp[i][j][k]=ways;
}
    int ways(vector<string>& pizza, int k) {
         n=pizza.size();
         m=pizza[0].size();
       this->pizza=pizza;
       prefix.assign(n+1,vector<long long>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
       prefix[i][j]=(pizza[i-1][j-1]=='A')+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(k,-1)));
        return fun(0,0,k-1);
    }
};