class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
         int l=intervals[0][0];
         int r=intervals[0][1];
         int cnt=0;
         for(int i=1;i<n;i++){
             int s=intervals[i][0];
             int e=intervals[i][1];
             if(s>=r){
                l=s;
                r=e;
             }
             else{
                if(s>=l && e<=r){
                    l=s;
                    r=e;
                }
               cnt++;
             }
         }
         return cnt;
    }
};