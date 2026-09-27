class Solution {
public:
int fun(int n,vector<int>& nums,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int take=nums[n]+fun(n-2,nums,dp);
        int notTake=fun(n-1,nums,dp);
        return dp[n]=max(take,notTake);
}
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,0);
       // return fun(n-1,nums,dp);
       if(n==1) return nums[0];
       if(n==2) return max(nums[0],nums[1]);
       dp[0]=nums[0];
       dp[1]=max(nums[1],nums[0]);
       for(int i=2;i<n;i++){
       
         int take =nums[i]+dp[i-2];
         int notTake=dp[i-1];
         dp[i]=max(take,notTake);
       }
        
        return dp[n-1];

    }
};