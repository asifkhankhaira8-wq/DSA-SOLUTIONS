class Solution {
public:
  const long long MOD = 1000000007;
  const long long BASE = 10;
 bool fun(int k,vector<int>& nums){
     unordered_map<long long,int>mp;
     int n = nums.size();
     long long power=1;
     for(int i=1;i<k;i++){
        power=(power*BASE)%MOD;
     }
      long long hash = 0;
        for (int i = 0; i < k; i++) {
            hash = (hash * BASE + nums[i]) % MOD;
        }
        mp[hash]++;
        for (int i = k; i < n; i++) {
            hash = (hash - nums[i-k] * power % MOD + MOD) % MOD;
            hash = (hash * BASE + nums[i]) % MOD;
            mp[hash]++;
           }
       for(auto it:mp){
       if(it.second==1){
        return true;
    }
}
return false;

}
    int smallestUniqueSubarray(vector<int>& nums) {
      int  n= nums.size();
        int low=1;
        int high=n;
        int ans=n;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(fun(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
    return ans;
    }
};