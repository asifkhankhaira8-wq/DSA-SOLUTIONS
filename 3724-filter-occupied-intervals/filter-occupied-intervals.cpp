class Solution {
public:
vector<vector<int>>interval;
void merge_intervals(vector<vector<int>>& nums){
   for(auto it:nums){
    if(!interval.empty() &&(interval.back()[1]>=it[0] || interval.back()[1]+1==it[0])){
       interval.back()[1]=max(interval.back()[1] , it[1]);
    }
    else interval.push_back(it);
   }
}
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int l=freeStart;
        int r=freeEnd;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        merge_intervals(occupiedIntervals);
        vector<vector<int>>ans;
        for(auto it:interval){
            if(r<it[0] || l>it[1]) ans.push_back(it);
            else{
                if(l<=it[0] && r>=it[1]){
                    continue;
                }
                else if(l>it[0] && r<it[1]){
                    ans.push_back({it[0],l-1});
                    ans.push_back({r+1,it[1]});
                }
                else if(r>=it[1]){
                    ans.push_back({it[0],l-1});
                }
                else ans.push_back({r+1,it[1]});
            }
            
        }
        return ans;
    }
};