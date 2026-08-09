class Solution {
public:
   bool fun(int k,vector<vector<int>>& mat, vector<vector<int>>pref){
        int n=mat.size();
        int m=mat[0].size();
        int minRow=n;
        int minCol=m;
        int maxRow=-1;
        int maxCol=-1;
       for(int i=0;i<=n-k;i++){
         for(int j=0;j<=m-k;j++){
               int sum= pref[i+k][j+k]-pref[i][j+k]-pref[i+k][j]+
               pref[i][j];
                if(sum!=k*k) continue;
                minRow=min(i,minRow);
                minCol=min(j,minCol);
                maxRow=max(i,maxRow);
                maxCol=max(j,maxCol);
            }
        }
        if(minRow==-1 ) return false;
        if(maxRow-minRow>=k || maxCol-minCol>=k){
            return true;
        }
        return false;
   }
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pref(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]=mat[i][j]+pref[i][j+1]+pref[i+1][j]-pref[i][j];
            }
        }
        int low=0;
        int high=min(n,m);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(fun(mid,mat,pref)){
              ans=mid;
              low=mid+1;
            }
            else high=mid-1;
        }
        return ans*ans;
    }
};