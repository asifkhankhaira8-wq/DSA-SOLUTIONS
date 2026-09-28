class Solution {
public:
int fun(int n,vector<int>& nums,vector<int>&dp){
    dp[0]=0;
    dp[1]=nums[0];
    for(int i=2;i<=n;i++){
        int notTake=dp[i-1];
        int take=-1e8;
        if(i>1) take=nums[i-1]+dp[i-2];

        dp[i]=max(take,notTake);
    }
    return dp[n];
}
 int solve(vector<int>&nums){
     int n=nums.size();
     vector<int>dp(n+1,-1);
    return fun(n,nums,dp);
 }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1(nums.begin()+1,nums.end());
        vector<int>temp2(nums.begin(),nums.end()-1);

        return max(solve(temp1),solve(temp2));
        
    }
};