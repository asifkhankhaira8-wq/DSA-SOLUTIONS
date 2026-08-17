class Solution {
public:
int fun(int x,int y,vector<vector<int>>& grid){
    queue<pair<int,int>>q;
    int n=grid.size();
        int m=grid[0].size();
         for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            if(grid[i][j]==2){
            q.push({i,j});
            }
           }
        }
    int time=-1;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    while(!q.empty()){
        int sz=q.size();
        time++;
        for(int i=0;i<sz;i++){
             auto it=q.front();
               q.pop();
             for(int j=0;j<4;j++){
                int nx=it.first+dx[j];
                int ny=it.second+dy[j];
                if(nx<n && nx>=0 && ny<m && ny>=0 && grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
             }  
                }
    }
                     return time;
}
    int orangesRotting(vector<vector<int>>& grid) {
        int time=fun(0,0,grid);
         int n=grid.size();
         int m=grid[0].size();
          for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                return -1;;
            }
           }
        }

        return time==-1 ? 0 : time ;
        
    }
};