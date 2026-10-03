class Solution {
public:
int fun(int i,int k,vector<int>& nums,vector<vector<int>>&dp){
     if(i==0){
        if(k%nums[i]==0) return k/nums[i];
        return 1e8;
     }
     if(dp[i][k]!=-1) return dp[i][k];
     int notTake=fun(i-1,k,nums,dp);
     int take=1e8;
     if(nums[i]<=k) take=1+fun(i,k-nums[i],nums,dp);
     return dp[i][k]=min(notTake,take);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
        }
        for(int i=0;i<n;i++) dp[i][0]=0;
         for(int i=1;i<n;i++){
            for(int k=1;k<=amount;k++){
                int notTake=dp[i-1][k];
                int take=1e8;
                 if(coins[i]<=k) take=1+dp[i][k-coins[i]];
                dp[i][k]=min(notTake,take);
            }
         }
         if(dp[n-1][amount]>=1e8) return -1;
         return dp[n-1][amount];
    }
};