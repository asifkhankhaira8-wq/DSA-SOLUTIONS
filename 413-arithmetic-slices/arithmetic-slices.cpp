class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
         for(int i=0;i<n-1;i++){
            int d=nums[i+1]-nums[i];
            int cnt=1;
            for(int j=i+1;j<n;j++){
               if(nums[j]-nums[j-1]!=d) break;
               cnt++;
            }
            if(cnt>=3) ans+=(cnt-2);
         }
         return ans;

    }
};