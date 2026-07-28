class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        vector<vector<int>> ans;
        int s = newInterval[0];
        int e = newInterval[1];
        int i = 0;
        while (i < n) {
            if (s <= intervals[i][1]) {
                s=min(s,intervals[i][0]);
                break;
            }
            ans.push_back(intervals[i]);
            i++;
        }
        int j = i;
        while (j < n) {
            if (e<=intervals[j][1]) {
                if (e>=intervals[j][0]) e=intervals[j][1];
                ans.push_back({s, e});
                break;
            }
            j++;
        }
        if(j==n) ans.push_back({s,e});
        int k=j;
        while(k<n){
            if(intervals[k][0]>e) {
                ans.push_back(intervals[k]);
            }
            k++;
        }
        return ans;
    }
};