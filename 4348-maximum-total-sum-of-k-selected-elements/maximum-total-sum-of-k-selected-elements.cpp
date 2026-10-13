class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0;
        while(mul>0 && k>0 && i<n){
         long long val=1LL*nums[i]*mul;
          sum+=val;
          mul--;
          i++;
          k--;
        }
        while(k>0 && i<n){
            sum+=nums[i];
            k--;
            i++;
        }
        return sum;
    }
};