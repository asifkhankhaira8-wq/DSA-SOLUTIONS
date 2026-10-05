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
        vector<int>prev(n+1,0);
        //return fun(n-1,n,nums,dp);
         prev[n]=1;
        for(int i=1;i<n;i++){
            if(nums[0]<nums[i]) prev[i]=1;
        } 
        
        for(int i=1;i<n;i++){
            vector<int>curr(n+1);
          for(int j=0;j<=n;j++){
                 int notTake=prev[j];
                 int take=0;
                 if(j==n) take=1+prev[i];
                 else{
            if(nums[i]<nums[j]) take=1+prev[i];}
            curr[j]=max(take,notTake);
            }
            prev=curr;
        }
     return prev[n]; 
    }
};