 class Solution {
public:
vector<vector<long long>>prefix;
vector<vector<long long>>dp;
long long fun(int i,int k,vector<vector<int>>& piles){
     if(k==0) return 0;
     if(i==0) return prefix[0][min(k,(int)piles[0].size())-1];
     if(dp[i][k]!=-1) return dp[i][k];
     long long maxi=0;

     for(int x = 0; x <= min(k, (int)piles[i].size()); x++) {
        long long val = 0;
        if(x > 0) val = prefix[i][x-1];
        val += fun(i-1, k-x, piles);
        maxi = max(maxi, val);
       }
     return dp[i][k]=maxi;
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        prefix.resize(n);
        for(int i=0;i<n;i++){
           prefix[i].resize(piles[i].size());
            prefix[i][0]=piles[i][0];
            for(int j=1;j<piles[i].size();j++){
             prefix[i][j]=prefix[i][j-1]+piles[i][j];
            }
        }
         dp.assign(n,vector<long long>(k+1,0));
        // return fun(n-1,k,piles);
        for(int i=1;i<=k;i++){
            dp[0][i]=prefix[0][min(i,(int)piles[0].size())-1];
        }
    for(int i=1;i<n;i++){
      for(int j=1;j<=k;j++){
       long long maxi=0;
       for(int x = 0; x <= min(j, (int)piles[i].size()); x++) {
         long long val = 0;
         if(x > 0) val = prefix[i][x-1];
         val += dp[i-1][j-x];
         maxi = max(maxi, val);
        }
       dp[i][j]=maxi;
            }
        }
        return dp[n-1][k];
    }
};