class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
         vector<unordered_map<long long,int>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long val=(long long)nums[i]-nums[j];
                int count =dp[j][val];
                ans+=count;
                dp[i][val]+=count+1;

            }
        }
        return ans;
    }
};