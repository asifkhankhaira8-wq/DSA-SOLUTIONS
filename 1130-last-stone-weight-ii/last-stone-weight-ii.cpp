class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total=0;
        int n=stones.size();
        for(int i=0;i<n;i++) total+=stones[i];
        vector<vector<bool>>dp(n,vector<bool>(total+1,0));
        dp[0][0]=true;
        dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int k=0;k<=total;k++){
               bool  notTake=dp[i-1][k];
               bool take=false;
               if(stones[i]<=k) take=dp[i-1][k-stones[i]];
               dp[i][k]=take || notTake;
            }
        }
        int mini=1e9;
        for(int i=0;i<=total;i++){
            if(dp[n-1][i]) mini=min(mini,abs(total-2*i));
        }
        return mini;
    }
};