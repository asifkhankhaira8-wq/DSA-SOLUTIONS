class Solution {
public:
int fun(int i,int b,vector<int>&prices,vector<vector<int>>&dp){
    int n=prices.size();
     if(i==n-1){
        if(b) return 0;
         return prices[i];
     }
     if(dp[i][b]!=-1) return dp[i][b];
     int take=INT_MIN;
     int notTake=fun(i+1,b,prices,dp);

     if(b) take=fun(i+1,0,prices,dp)-prices[i];
     if(!b) take=prices[i];

     return dp[i][b]=max(take,notTake);
     
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};