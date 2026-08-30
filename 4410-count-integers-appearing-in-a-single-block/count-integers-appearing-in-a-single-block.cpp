class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0;
        while(i<n){
           mp[nums[i]]++;
            int idx=i;
            while(idx<n && nums[idx]==nums[i]){
                idx++;
            }
            i=idx;

        }
        int cnt = 0;
        for(auto &p : mp){
            if(p.second == 1){
                cnt++;
            }
        }
        return cnt;

        
    }
};