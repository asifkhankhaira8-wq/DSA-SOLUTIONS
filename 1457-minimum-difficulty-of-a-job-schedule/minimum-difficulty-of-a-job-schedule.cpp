class Solution {
public:
vector<vector<int>>dp;
int fun(int i,int d,vector<int>&nums){
    if(i==0){
        if(d==1) return nums[0];
         return 1e9;
    }
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
        dp.assign(n,vector<int>(d+1,-1));
        return fun(n-1,d,jobDifficulty);
    }
};