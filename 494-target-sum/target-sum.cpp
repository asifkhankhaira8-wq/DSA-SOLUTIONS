class Solution {
public:
 int sum=0;
int fun(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
    if(k>sum || k+sum<0){
        return 0;
    }
      if(i==0){
        int cnt=0;
        if(nums[i]-k==0) cnt++;
        if(nums[i]+k==0) cnt++;
        return cnt;
      }
        if(dp[i][sum+k]!=-1) return dp[i][sum+k];
          
      int negTake=fun(i-1,k+nums[i],nums,dp);
      int posTake=fun(i-1,k-nums[i],nums,dp);
 
          return dp[i][sum+k]=negTake+posTake;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
           sum+=nums[i];
        }
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return fun(n-1,target,nums,dp);
    }
};