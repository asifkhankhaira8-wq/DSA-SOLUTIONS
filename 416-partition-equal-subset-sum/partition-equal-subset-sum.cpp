class Solution {
public:
    bool canPartition(vector<int>& nums) {
          int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        if(target%2) return false;
        target/=2;
       vector<vector<bool>>dp(n,vector<bool>(target+1,0));
      if(nums[0]<=target) dp[0][nums[0]]=true;
        dp[0][0]=true;
     for(int i=1;i<n;i++){
        for(int k=0;k<=target;k++){
            bool notTake=dp[i-1][k];
            bool take=false;
            if(nums[i]<=k) take=dp[i-1][k-nums[i]];
            dp[i][k]=notTake || take;
        }
     }    
     return dp[n-1][target];
    }
};