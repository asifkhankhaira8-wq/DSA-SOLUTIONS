class Solution {
public:
vector<int>dp;
int fun(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int x=floor(sqrt(n));
    int mini=n;
    for(int i=x;i>=2;i--){
        int val=i*i;
       mini=min(mini,1+fun(n-val));
    }
    return dp[n]= mini;
}
    int numSquares(int n) {
        dp.assign(n+1,-1);
        return fun(n);
        
    }
};