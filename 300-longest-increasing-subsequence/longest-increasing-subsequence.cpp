class Solution {
public:
int fun(int i,int j,vector<int>&nums, vector<vector<int>>&dp){
    int n=nums.size();
    if(i==0){
        if(j==n) return 1;
        if(nums[i]<nums[j]) return 1;
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j]; 
    int notTake=fun(i-1,j,nums,dp);
    int take=0;
    if(j==n) take=1+fun(i-1,i,nums,dp);
    else{
      if(nums[i]<nums[j]) take=1+fun(i-1,i,nums,dp);}

    return dp[i][j]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        //return fun(n-1,n,nums,dp);
         dp[0][n]=1;
        for(int i=1;i<n;i++){
            if(nums[0]<nums[i]) dp[0][i]=1;
        } 
        
        for(int i=1;i<n;i++){
          for(int j=0;j<=n;j++){
                 int notTake=dp[i-1][j];
                 int take=0;
                 if(j==n) take=1+dp[i-1][i];
                 else{
            if(nums[i]<nums[j]) take=1+dp[i-1][i];}
            dp[i][j]=max(take,notTake);
            }
        }
     return dp[n-1][n]; 
    }
};