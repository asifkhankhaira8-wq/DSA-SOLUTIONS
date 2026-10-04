class Solution {
public:
int fun(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
    if(k==0) return 1;
     if(i==0){
        if(k%nums[i]==0) return 1;
        return 0;
     }
     if(dp[i][k]!=-1) return dp[i][k];
     int notTake=fun(i-1,k,nums,dp);
     int take=0;
     if(nums[i]<=k) take=fun(i,k-nums[i],nums,dp);

     return dp[i][k]= take+notTake;
}
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
       vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
     if(coins[0]<=amount){
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
          }
       }
      for(int i=0;i<n;i++) dp[i][0]=1;
     for(int i=1;i<n;i++){
        for(int k=1;k<=amount;k++){
      unsigned long long notTake = dp[i-1][k];

            unsigned long long take = 0;
      if(coins[i]<=k) take=dp[i][k-coins[i]];
       dp[i][k]= take+notTake;
        }
     }
     return dp[n-1][amount];
    }
};