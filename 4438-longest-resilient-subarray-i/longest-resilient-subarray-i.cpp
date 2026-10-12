class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int len=1;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            int mod=nums[i]%k;
            for(int j=i+1;j<n;j++){
                if(nums[j]%k!=mod) break;
                sum+=nums[j];
                if(sum%k==mod) len=max(len,j-i+1);
            }
        }
        return len;
    }
};