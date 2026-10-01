class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int tot=k;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,0)));
   
      for(int i=0;i<k;i++) dp[n-1][0][i]=prices[n-1];
         for(int i=n-2;i>=0;i--){
            for(int b=0;b<2;b++){
                for(int k=0;k<tot;k++){

     int notBuy=dp[i+1][b][k];
     int buy;
     if(b) buy=dp[i+1][0][k]-prices[i];
     else  buy=dp[i+1][1][k+1]+prices[i];

    dp[i][b][k]=max(buy,notBuy);
                }
            }
         }
         
         return dp[0][1][0];
    }
};