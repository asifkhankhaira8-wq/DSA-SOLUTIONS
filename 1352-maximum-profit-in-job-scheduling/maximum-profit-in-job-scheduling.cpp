class Solution {
public:
vector<int>dp;
vector<tuple<int,int,int>>nums;
int fun(int i){
    int  n=nums.size();
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int notTake=fun(i+1);
    int nextJob=n;
    int l=i+1;
    int h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(get<0>(nums[mid])>=get<1>(nums[i])){
            nextJob=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    int take=get<2>(nums[i])+fun(nextJob);
  
    return dp[i]=max(take,notTake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        nums.clear();
        nums.resize(n);
        for(int i=0;i<n;i++){
            nums[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(nums.begin(),nums.end());
        dp.assign(n,-1);
        return fun(0);

    }
};