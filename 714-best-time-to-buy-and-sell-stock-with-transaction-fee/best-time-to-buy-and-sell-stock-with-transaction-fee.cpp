class Solution {
public:
int fun(int i,int b,int fee,vector<int>&prices , vector<vector<int>>&dp){
    int n=prices.size();
    if(i==n-1) {
        if(!b) return prices[n-1];
        return 0;
    }
    if(dp[i][b]!=-1) return dp[i][b];
    int notTake=fun(i+1,b,fee,prices,dp);
    int take;
    if(b) take = fun(i+1,0,fee,prices,dp) - prices[i] - fee;
    else take=fun(i+1,1,fee,prices,dp) + prices[i];
    return dp[i][b]=max(take,notTake); 
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(0,1,fee,prices,dp);
    }
};