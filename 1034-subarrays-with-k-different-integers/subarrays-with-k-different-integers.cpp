class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int n=nums.size();
        int left=0;
        int maxi=0;
        for(int right=0;right<n;right++){
          mp[nums[right]]++;
          while(mp.size()>k){
              mp[nums[left]]--;
              if(mp[nums[left]]==0) mp.erase(nums[left]);
              left++;
          }
        maxi+=right-left+1;
        }
        return maxi;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};