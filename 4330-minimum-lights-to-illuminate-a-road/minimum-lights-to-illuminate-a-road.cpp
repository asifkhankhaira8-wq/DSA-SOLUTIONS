class Solution {
public:
vector<vector<int>>arr;
 void merge_intervals(vector<int>&nums){
vector<vector<int>>intervals;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int v=nums[i];
        if(v!=0) intervals.push_back({max(0,i-v),min(n-1,i+v)});
    }
    sort(intervals.begin(),intervals.end());
    for(auto it:intervals){
       if(!arr.empty() && arr.back()[1]>=it[0]){
            arr.back()[1]=max(arr.back()[1],it[1]);
       }
       else arr.push_back(it);
    }
 }
    int minLights(vector<int>& lights) {
        merge_intervals(lights);
        int n=lights.size();
        vector<bool>nums(n,false);
        int ans=0;
     for(auto it:arr)for(int i=it[0];i<=it[1];i++) nums[i]=true;
     for(int i=0;i<n;i++){
        int idx=i;
        int cnt=0;
        while(idx<n && !nums[idx]) {
            idx++;
            cnt++;
        }
        if(i!=idx) i=idx;
        ans+=(cnt+2)/3;
     }
        return ans;
    }
};