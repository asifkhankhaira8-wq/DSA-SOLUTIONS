class Solution {
public:
void fun(int i,int k,vector<int>& nums,vector<int>temp,vector<vector<int>>&ans){
    int n=nums.size();
    if(i==n){
      if(k==0){
        ans.push_back(temp);
      }
        return ;
    }
    fun(i+1,k,nums,temp,ans);
    if(nums[i]<=k){
        temp.push_back(nums[i]);
        fun(i,k-nums[i],nums,temp,ans);
    }
   
} 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        fun(0,target,candidates,{},ans);
        return ans;
    }
};