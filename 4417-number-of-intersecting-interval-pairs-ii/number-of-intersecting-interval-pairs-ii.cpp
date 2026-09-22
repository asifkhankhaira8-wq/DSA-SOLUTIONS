class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();

      long long  cnt=0;
        for(int i=0;i<n;i++){
            int right=intervals[i][1];

            int low=i+1;
            int high=n-1;

            int idx=n;
            while(low<=high){
                int mid=low+(high-low)/2;
                int l=intervals[mid][0];
                if( l>right){
                    idx=mid;
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            cnt+=(idx-i-1);
        }
        return cnt;
    }
};