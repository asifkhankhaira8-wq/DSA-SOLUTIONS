class Solution {
public:
vector<vector<int>>dp;
int fun(int i,int d,vector<int>&nums){
    if(d==1){
        return *max_element(nums.begin(),nums.begin()+i+1);
    }
    if(dp[i][d]!=-1) return dp[i][d];
        int maxi = 0;
        int mini = INT_MAX;
   for(int k=i;k>=(d-1);k--){
         maxi=max(maxi,nums[k]);
        int x=fun(k-1,d-1,nums);
        mini=min(mini,maxi+x);
   }
  return dp[i][d]=mini;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1;
        dp.assign(n,vector<int>(d+1,1e9));
     //   return fun(n-1,d,jobDifficulty);
      vector<int> nums=jobDifficulty;
     int D=d;
     for(int i=0;i<n;i++){
        dp[i][1]=*max_element(nums.begin(),nums.begin()+i+1);
     }
     for(int i=0;i<n;i++){
        for(int d=2;d<=D;d++){
            int maxi = 0;
           int mini = INT_MAX;
        for(int k=i;k>=(d-1);k--){
          maxi=max(maxi,nums[k]);
          int x=fun(k-1,d-1,nums);
           mini=min(mini,maxi+x);
       }
       dp[i][d]=mini;
        }
     }
     return dp[n-1][d];
    }
};