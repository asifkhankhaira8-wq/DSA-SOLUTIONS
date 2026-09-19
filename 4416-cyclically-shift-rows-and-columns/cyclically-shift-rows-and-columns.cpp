class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
         vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             ans[i][(j-rowShift[i]+n)%n]=grid[i][j];
            }
        }
        vector<vector<int>> result(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             result[(i-colShift[j]+n)%n][j]=ans[i][j];
            }
        }
        return result;
    }
};