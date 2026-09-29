class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         int maxi=-1e9;
          for(int i=1;i<n-1;i++) {
            for(int j=1;j<m-1;j++) {
                maxi=max(maxi,grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            int best=-1e9,sum=grid[i][0];
            for(int j=1;j<m;j++){
              sum+=grid[i][j];
              best=max(best,sum);
              sum=max(grid[i][j],sum);
            }
            maxi=max(maxi,best);
        }
         for(int i=0;i<m;i++){
            int best=-1e9,sum=grid[0][i];
            for(int j=1;j<n;j++){
              sum+=grid[j][i];
              best=max(best,sum);
             sum=max(grid[j][i],sum);
            }
            maxi=max(maxi,best);
        }
        return maxi;
    }
};