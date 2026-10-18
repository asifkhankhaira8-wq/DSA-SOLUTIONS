class Solution {
public:
    int minDeletions(vector<int>& nums) {
      int cnt=0;
      int n=nums.size();
      int i=0;
      while(i<n){
          int idx=i+1;
          while(idx<n && nums[idx]==nums[i]){
              cnt++;
              idx++;
          }
          i=idx;
      }
      return cnt;
    }
};