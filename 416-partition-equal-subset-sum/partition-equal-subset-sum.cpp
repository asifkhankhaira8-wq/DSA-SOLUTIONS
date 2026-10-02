class Solution {
public:
    bool canPartition(vector<int>& nums) {
          int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        if(target%2) return false;
        target/=2;
     //  vector<vector<bool>>dp(n,vector<bool>(target+1,0));
      vector<bool>prev(target+1,0);
      if(nums[0]<=target) prev[nums[0]]=true;
        prev[0]=true;
     for(int i=1;i<n;i++){
        vector<bool>curr(target+1,false);
        for(int k=0;k<=target;k++){
            bool notTake=prev[k];
            bool take=false;
            if(nums[i]<=k) take=prev[k-nums[i]];
            curr[k]=notTake || take;
        }
        prev=curr;
     }    
     return prev[target];
    }
};