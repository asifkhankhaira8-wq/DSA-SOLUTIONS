class Solution {
public:
    int fun(int i,vector<int>&arr,int k,vector<int>&dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi=0;
        int ans=0;

        for(int idx=i;idx>=max(0,i-k+1);idx--){
            maxi=max(maxi,arr[idx]);

            int len=i-idx+1;
            int val=len*maxi+fun(idx-1,arr,k,dp);

            ans=max(ans,val);
        }

        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr,int k){
        int n=arr.size();
        vector<int>dp(n+1,0);
       // return fun(n-1,arr,k,dp);
       for(int i=0;i<n;i++){
          int maxi=0;
          int ans=0;
        for(int idx=i;idx>=max(0,i-k+1);idx--){
            maxi=max(maxi,arr[idx]);
            int len=i-idx+1;
            int val=len*maxi+fun(idx-1,arr,k,dp);
            ans=max(ans,val);
        }
         dp[i]=ans;
       }
       return dp[n-1];
    }
};