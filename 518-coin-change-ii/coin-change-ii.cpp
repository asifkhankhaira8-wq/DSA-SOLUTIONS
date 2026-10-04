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
      vector<vector<int>>dp(n,vector<int>(amount+1,-1));
      return fun(n-1,amount,coins,dp);
    }
};