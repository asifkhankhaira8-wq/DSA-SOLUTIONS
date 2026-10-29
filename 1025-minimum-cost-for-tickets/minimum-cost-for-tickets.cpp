class Solution {
public:
 vector<int>dp;
 int fun(int i,vector<int>&days,vector<int>&costs){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
   int idx=upper_bound(days.begin(),days.begin()+i,days[i]-7)-days.begin();
    int one=costs[0]+fun(i-1,days,costs);
    int seven=costs[1]+fun(idx-1,days,costs);
  idx=upper_bound(days.begin(),days.begin()+i,days[i]-30)-days.begin();
    int month=costs[2]+fun(idx-1,days,costs);
    return dp[i]=min(one,min(seven,month));
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.assign(n,0);
        dp[0]=min({costs[0],costs[1],costs[2]});
        for(int i=1;i<n;i++){
int idx=upper_bound(days.begin(),days.begin()+i,days[i]-7)-days.begin(); 
    int one=costs[0]+dp[i-1];
    int seven=costs[1];
    if(idx!=0) seven=costs[1]+dp[idx-1];
  idx=upper_bound(days.begin(),days.begin()+i,days[i]-30)-days.begin();
    int month=costs[2];
    if(idx!=0) month=costs[2]+dp[idx-1];
     dp[i]=min(one,min(seven,month));
        }
        return dp[n-1];
    }
};