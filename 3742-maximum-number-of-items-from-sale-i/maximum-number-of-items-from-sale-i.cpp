class Solution {
public:
vector<int> maxItems(vector<vector<int>>& nums,int budget,int idx) {
    int n =nums.size();
    vector<int>dp(budget+1,0);
    for(int i=0;i<n;i++){
        if(i==idx) continue;
       int price=nums[i][0];
        int item=nums[i][1];
        for(int b=budget;b>=price;b--){
            dp[b]=max(dp[b], dp[b - price] + (item+1));
        }
    }
    return dp;
}
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<vector<int>> nums(n);
        for(int i=0;i<n;i++){
           int factor=items[i][0];
            nums[i]={items[i][1],0};
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%factor==0) nums[i][1]++;
            }
        }
        int mini=1e9;
        int idx=-1;
        for(int i=0;i<n;i++) {
            if(nums[i][0]==mini && nums[i][1]>nums[idx][1]){
              idx=i;
            }
            else if(nums[i][0]<mini){
            mini=min(items[i][1],mini);
            idx=i;
            }
          }
         if(budget<items[idx][1]) return 0; 
        int itemsbymini=nums[idx][1]+budget/nums[idx][0];

        int low=0;
        int high=budget;
        int maxi=itemsbymini;
        vector<int> dp = maxItems(nums, budget, idx);
        while(low<=high){
              int total_item = dp[budget - low];
            int copies = low / nums[idx][0];
                if (copies > 0) {
                    total_item += copies + nums[idx][1];
                              }
              maxi=max(maxi,total_item);
              low++;
        }
        return maxi;
    }
};