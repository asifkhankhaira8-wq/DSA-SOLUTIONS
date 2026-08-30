class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<bool>vis(100,0);
        int cnt=0;
        int i=0;
        while(i<n){
            if(mp.find(nums[i])!=mp.end()) {
               if(!vis[nums[i]]) {
                vis[nums[i]]=true;
                cnt--;
               }
            }  
            else {
                mp[nums[i]]=1;
                cnt++;
                }

            int idx=i;
            while(idx<n && nums[idx]==nums[i]){
                idx++;
            }
            i=idx;

        }
        return cnt;

        
    }
};