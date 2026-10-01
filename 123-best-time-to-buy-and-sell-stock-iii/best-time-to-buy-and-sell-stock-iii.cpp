class Solution {
public:
int fun(int i,int b,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
    int n=prices.size();
     if(k>=2) return 0;
     if(i==n-1){
        if(!b) return prices[n-1] ;
        return 0;
     }
     if(dp[i][b][k]!=-1) return dp[i][b][k];
     int notBuy=fun(i+1,b,k,prices,dp);
     int buy;
     if(b) buy=fun(i+1,0,k,prices,dp)-prices[i];
     else buy=fun(i+1,1,k+1,prices,dp)+prices[i];

     return dp[i][b][k]=max(buy,notBuy);
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return fun(0,1,0,prices,dp);
    }
};