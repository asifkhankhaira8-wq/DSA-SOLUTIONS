class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
         unordered_map<string,int>mp2;
         int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                mp[i]++;
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                string x=to_string(min(nums[i],nums[i-1]));
                string y=to_string(max(nums[i],nums[i-1]));
                 mp2[x+","+y]++;
            }
        }
        int sum=0;
        for(auto it:mp){
            sum+=it.second;
        }
        int maxi=0;
        for(auto it:mp2){
            maxi=max(maxi,it.second);
        }
        return maxi+sum;
    }
};