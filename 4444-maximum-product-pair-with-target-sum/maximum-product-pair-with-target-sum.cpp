class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n=nums.size();
        pair<int,int>index={-1,-1};
        int maxi=-1e9;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
               if(nums[i]>nums[j] && nums[i]+nums[j]==target){
                     if(nums[i] * nums[j] > maxi){
                        maxi=nums[i]*nums[j];
                        index.first=i;
                        index.second=j;
                     }
               }
            }
        }
        return {index.first,index.second};
    }
};