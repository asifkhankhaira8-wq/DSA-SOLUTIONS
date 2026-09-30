class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        int x=1;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
              if(nums[i]==nums[i-1]){
                 if(x<k)  ans.push_back(nums[i]),x++;
              }
              else {
                ans.push_back(nums[i]);
                x=1;
              }
        }
        return ans;
    }
};