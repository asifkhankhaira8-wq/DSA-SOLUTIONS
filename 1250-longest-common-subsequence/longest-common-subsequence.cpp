class Solution {
public:
int fun(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
  int same=0;
  int maxi=0;
  if(text1[i]==text2[j]) same=1+fun(i-1,j-1,text1,text2,dp);
 else { maxi=max(maxi,fun(i-1,j,text1,text2,dp));
  maxi=max(maxi,fun(i,j-1,text1,text2,dp));
 }
  return dp[i][j]=max(same,maxi);

  //recursion stack O(n+m)
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>prev(m+1,0);
       for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
        for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(curr[j-1],prev[j]);
        }
        prev=curr;
       }
       
    return prev[m];
    }
};