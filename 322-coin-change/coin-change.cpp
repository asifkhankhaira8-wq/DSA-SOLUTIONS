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
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int x=fun(n-1,amount,coins,dp);
        if(x>=1e8) return -1;
        return x;
    }
};