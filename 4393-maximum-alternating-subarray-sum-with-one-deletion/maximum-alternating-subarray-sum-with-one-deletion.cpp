class Solution {
public:
long long fun(int i,int parity, int b,vector<int>&nums,vector<vector<vector<long long>>>& dp){
    int n = nums.size() ;
    if(i>=n) return 0;
    long long val=0;
     long long ans = 0 ;
     if(dp[i][parity][b]!=LLONG_MIN) return dp[i][parity][b];
    if(parity) val=-1LL*nums[i];
    else val=nums[i];
 
    long long take=val+fun(i+1,1-parity,b,nums,dp);
    ans = max(ans , take) ;
    if(!b) ans=max(ans,fun(i+1,parity,1,nums,dp));

    return dp[i][parity][b]=ans;
}
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<vector<long long>>> dp(
            n + 1 ,
            vector<vector<long long>>(2 , vector<long long>(2 , LLONG_MIN))
        ) ;

        long long ans = LLONG_MIN ;
        int i = 0 ;

        while(i < n) {
            long long curr = nums[i] + fun(i + 1 , 1 , 0 , nums , dp) ;
            ans = max(ans , curr) ;
            i++ ;
        }

        return ans ;
    }
};