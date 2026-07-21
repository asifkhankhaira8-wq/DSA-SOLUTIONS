class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int right=0;right<n;right++){
         sum+=nums[right];
         int res=sum-goal;
         cnt+=mp[res];
         mp[sum]++;
        }
        return cnt;
    }
};