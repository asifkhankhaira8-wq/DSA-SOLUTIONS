class Solution {
public:
void bfs(int x,int y,vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    q.push({x,y});
     grid[x][y]='0';
     int dx[4]={0,0,1,-1};
     int dy[4]={1,-1,0,0};
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1'){
                grid[nx][ny]='0';
                q.push({nx,ny});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};