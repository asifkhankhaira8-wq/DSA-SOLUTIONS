class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        //if(goal==0) return n*(n+1)/2;
        int sum=0;
        int cnt=0;
        int left=0;
        for(int right=0;right<n;right++){
          sum+=nums[right];
          while(sum>goal){
            sum-=nums[left];
            left++;
          }
          int temp=left;
          while(temp<=right && sum==goal){
            cnt++;
            if(nums[temp]==1){
                break;
            }
             temp++;
          }
        }
        return cnt;
        
    }
};