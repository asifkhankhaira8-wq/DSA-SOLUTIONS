class Solution {
public:
vector<vector<int>>dp;
int fun(int l,int h){
    if(l>h) return 1;
    if(dp[l][h]!=-1) return dp[l][h];
    int ans=0;
    for(int k=l;k<=h;k++){
      int left=fun(l,k-1);
      int right=fun(k+1,h);
      ans += left * right;
    }
    return dp[l][h]=ans;
}
    int numTrees(int n) {
        dp.assign(n+1,vector<int>(n+1,-1));
        return fun(1,n);
    }
};