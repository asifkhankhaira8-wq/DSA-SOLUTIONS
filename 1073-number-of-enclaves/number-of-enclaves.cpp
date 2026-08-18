class Solution {
public:
void bfs(int x,int y,vector<vector<int>>& board){
     int n=board.size();
        int m=board[0].size();
         queue<pair<int,int>>q;
         board[x][y]=0;
         q.push({x,y});
      int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && nx>=0 && ny<m && ny>=0 && board[nx][ny]==1){
                    board[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
            
        }

}
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
       int m=grid[0].size();
       vector<vector<bool>> vis(n,vector<bool>(m,false));
       for(int i=0;i<n;i++){
        if(grid[i][0]==1){
        bfs(i,0,grid);}
        if(grid[i][m-1]==1)
            bfs(i,m-1,grid);
       }
       for(int j=1;j<m-1;j++){
        if(grid[0][j]==1)
            bfs(0,j,grid);
        if(grid[n-1][j]==1)    
            bfs(n-1,j,grid);
       }
       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                ans++;
            }
        }}
        return ans;

    }
};