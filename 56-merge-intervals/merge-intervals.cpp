class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
         vector<vector<int>>ans;
         ans.push_back(intervals[0]);
         for(int i=1;i<n;i++){
            int x=ans.size();
             int s=intervals[i][0];
             int e=intervals[i][1];
             if(s>ans[x-1][1]){
                ans.push_back(intervals[i]);
             }
             else{
                 ans[x-1][1]=max(ans[x-1][1],e);
             }
         }
         return ans;

    }
};