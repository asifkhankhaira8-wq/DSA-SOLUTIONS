class Solution {
public:
int fun(int i,int b,vector<int>&prices,vector<vector<int>>&dp){
    int n=prices.size();
    if(i==n-1){
        if(b==0) return prices[n-1];
         return 0;
    }
    if(dp[i][b]!=-1) return dp[i][b]; 
    int notBuy=fun(i+1,b,prices,dp);
    int buy;
    if(b) buy=fun(i+1,0,prices,dp)-prices[i];
    else   buy=prices[i]+fun(i+1,1,prices,dp);

    return dp[i][b]=max(notBuy,buy);
}
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
    // vector<vector<int>>dp(n,vector<int>(2,0));
     int bought=0;
     int sold=prices[n-1];
     // dp[n-1][0]=prices[n-1]; 
      for(int i=n-2;i>=0;i--){
        vector<int>curr(2,0);
        for(int b=0;b<2;b++){
        int notBuy;
        if(b)notBuy=bought;
        else notBuy=sold;
        int buy;
        if(b) buy=sold-prices[i];
        else buy=bought+prices[i];
       curr[b]=max(buy,notBuy);
      }
      bought=curr[1];
      sold=curr[0];
      }

      return bought;
          } 
};