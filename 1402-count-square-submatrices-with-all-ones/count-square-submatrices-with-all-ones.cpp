class Solution {
public:
int solve(int n,vector<int>&lastCol){
    int m=lastCol.size();
    int l=-1;
    int  cnt=0;
     for(int i=0;i<m;i++){
         if(lastCol[i]<n){
            l=i;
         }
         if(i-l==n){
            cnt++;
            l++;
         }
     }
     return cnt;
}
int fun(vector<int>&lastCol,int n){
    int ans=0;
    for(int size=1;size<=n;size++){
      ans+=solve(size,lastCol);
      }
   return ans;
}
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>lastCol(m,0);
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(matrix[i][j]==0) lastCol[j]=0;
              else lastCol[j]+=matrix[i][j];
          }
          int squares=fun(lastCol,i+1);
          ans+=squares;
        }
       return ans;
    }
};