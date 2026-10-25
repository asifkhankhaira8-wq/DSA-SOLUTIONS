class Solution {
public:
vector<vector<int>>dp;
int fun(int l,int h){
    if(l>h) return 0;
    if(l==h){
      return 1;
    }
    if(dp[l][h]!=-1) return dp[l][h];
    int ans=0;
    for(int k=l;k<=h;k++){
      int left=fun(l,k-1);
      int right=fun(k+1,h);
      if(left!=0 && right!=0 ) ans+=(left*right);
      else{
          ans+=left;
          ans+=right;
      }
    }
    return dp[l][h]=ans;
}
    int numTrees(int n) {
        dp.assign(n+1,vector<int>(n+1,-1));
        return fun(1,n);
    }
};