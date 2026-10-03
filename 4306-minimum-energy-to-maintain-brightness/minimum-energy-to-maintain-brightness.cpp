class Solution {
public:
vector<vector<int>> merge_interval(vector<vector<int>>& intervals){
    int n=intervals.size();
    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    
    for(auto it:intervals){
       if(ans.empty() || ans.back()[1]<it[0]){
        ans.push_back(it);
       }
       else ans.back()[1]=max(it[1],ans.back()[1]);
    }
    return ans;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
            intervals=merge_interval(intervals);
         int req=ceil((double)brightness/3);
         long long ans=0;
         for(auto it:intervals){
            ans+=(it[1]-it[0])+1;
         }
         return ans*req;
    }
};