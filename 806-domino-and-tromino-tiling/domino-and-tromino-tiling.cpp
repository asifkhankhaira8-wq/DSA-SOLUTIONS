class Solution {
public:
const int MOD=1e9+7;
vector<vector<int>>dp;
int fun(int i,int j){
    if(i==0) {
        if(j==0) return 1;
        return 0;
    }
    if(i<0){
        if(j==0) return 1;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j]%MOD;
    int ans=0;
    if(j==0){
        if(i>=1) ans=(ans+fun(i-2,0))%MOD;
         ans=(ans+fun(i-1,0))%MOD;
         ans=(ans+fun(i-1,1))%MOD;
         ans=(ans+fun(i-1,2))%MOD;
            
       }
      else if(j==1){
         ans=(ans+fun(i-1,2))%MOD;
         ans=(ans+fun(i-2,0))%MOD;
      } 
      else if(j==2){
          ans=(ans+fun(i-1,1))%MOD;
          ans=(ans+fun(i-2,0))%MOD;
      }
      return dp[i][j]=ans%MOD;

}
    int numTilings(int n) {
        dp.assign(n,vector<int>(3,-1));
        return fun(n-1,0);
    }
};