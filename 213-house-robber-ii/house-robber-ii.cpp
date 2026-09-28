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
 int solve(vector<int>&nums){
     int n=nums.size();
     vector<int>dp(n,-1);
    return fun(n-1,nums,dp);
 }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1(nums.begin()+1,nums.end());
        vector<int>temp2(nums.begin(),nums.end()-1);

        return max(solve(temp1),solve(temp2));
        
    }
};