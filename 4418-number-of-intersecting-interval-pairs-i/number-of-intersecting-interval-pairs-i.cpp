class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
       int cnt=0;
       int n=intervals.size();
        for(int i=0;i<n;i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            for(int j=i+1;j<n;j++){
                int left=intervals[j][0];
                int right=intervals[j][1];
                if(left>r || right<l){
                    continue;
                }
                else cnt++;
            }
        }
        return cnt;
        
    }
};